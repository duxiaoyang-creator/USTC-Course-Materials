import pandas as pd
import requests
import time
import io  # 新增：用于解决 pandas 报错

# 1. 基础配置
# 1. 基础配置
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/152.0.0.0 Safari/537.36 Edg/152.0.0.0",
    
    # ！！！重点：下面这个 Cookie 你必须重新去浏览器复制一个最新的填进来！！！
    "Cookie": "cn_com_southsoft_gms=45c11086-ee20-4117-8fce-5f6543755285", 
    
    # 完美伪装浏览器的其他标头
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "Cache-Control": "max-age=0",
    "Referer": "https://xspt.ustc.edu.cn/xxgs/bktm",
    "Sec-Ch-Ua": '"Chromium";v="152", "Not?A_Brand";v="24", "Microsoft Edge";v="152"',
    "Sec-Ch-Ua-Mobile": "?0",
    "Sec-Ch-Ua-Platform": '"Windows"',
    "Sec-Fetch-Dest": "document",
    "Sec-Fetch-Mode": "navigate",
    "Sec-Fetch-Site": "same-origin",
    "Sec-Fetch-User": "?1",
    "Upgrade-Insecure-Requests": "1"
}

PCID = "5AF15376D84EFF3FE063B846A8C03833"

colleges = {
    "001": "数学科学学院",
    "203": "物理学院",
    "204": "管理学院",
    "206": "化学与材料科学学院",
    "208": "地球和空间科学学院",
    "209": "工程科学学院",
    "210": "信息科学技术学院",
    "211": "人文与社会科学学院",
    "214": "核科学技术学院",
    "215": "计算机科学与技术学院",
    "219": "微电子学院",
    "221": "网络空间安全学院",
    "229": "人工智能与数据科学学院",
    "232": "火灾实验室",
    "240": "环境学院",
    "910": "生命科学与医学部",
    "998": "少年班学院"
}

all_data_frames = []

for code, name in colleges.items():
    url = f"https://xspt.ustc.edu.cn/xxgs/bktm?yxsh={code}&pcid={PCID}"
    print(f"正在抓取: {name} ({code})...")
    
    try:
        response = requests.get(url, headers=headers, timeout=10)
        response.encoding = 'utf-8' 
        
        # 拦截判断：检查服务器是否还是返回报错页面
        if "尚未开放" in response.text:
            print("  -> 抓取失败：服务器返回了'尚未开放'。说明 Cookie 可能已过期，请重新抓包获取！")
            break
        if "登录" in response.text or "统一身份认证" in response.text:
            print("  -> 抓取失败：需要登录。请重新抓包获取最新的 Cookie！")
            break
            
        # 使用 io.StringIO 包装，彻底解决 [Errno 2] 的报错问题
        tables = pd.read_html(io.StringIO(response.text))
        
        if tables:
            df = tables[0] 
            df['学院代码'] = code
            df['学院名称'] = name
            all_data_frames.append(df)
            print(f"  -> 成功获取 {len(df)} 条记录")
        else:
            print(f"  -> 页面中未找到表格数据")
            
    except Exception as e:
        print(f"  -> 抓取异常: {e}")
        
    time.sleep(1)

if all_data_frames:
    final_df = pd.concat(all_data_frames, ignore_index=True)
    final_df.dropna(subset=['学号'], inplace=True) 
    final_df.to_excel("推免生名单汇总.xlsx", index=False)
    print(f"\n全部抓取完成！已保存为: 推免生名单汇总.xlsx")