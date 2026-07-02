    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (shabishiyan_P)
        ;%
            section.nData     = 82;
            section.data(82)  = dumData; %prealloc

                    ;% shabishiyan_P.BandLimitedWhiteNoise_Cov
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_P.BandLimitedWhiteNoise1_Cov
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% shabishiyan_P.BandLimitedWhiteNoise_seed
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% shabishiyan_P.BandLimitedWhiteNoise1_seed
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% shabishiyan_P.Out1_Y0
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% shabishiyan_P.Constant_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% shabishiyan_P.Constant_Value_o
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% shabishiyan_P.Constant1_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% shabishiyan_P.PosRef1_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% shabishiyan_P.PosRef2_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% shabishiyan_P.GTS400PVsInitialization_P1_Size
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% shabishiyan_P.GTS400PVsInitialization_P1
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 12;

                    ;% shabishiyan_P.GTS400PVsInitialization_P2_Size
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 13;

                    ;% shabishiyan_P.GTS400PVsInitialization_P2
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 15;

                    ;% shabishiyan_P.GTS400PVsInitialization_P3_Size
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 16;

                    ;% shabishiyan_P.GTS400PVsInitialization_P3
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 18;

                    ;% shabishiyan_P.GTS400PVsInitialization_P4_Size
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% shabishiyan_P.GTS400PVsInitialization_P4
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 24;

                    ;% shabishiyan_P.GTS400PVsInitialization_P5_Size
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 28;

                    ;% shabishiyan_P.GTS400PVsInitialization_P5
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 30;

                    ;% shabishiyan_P.GTS400PVsInitialization_P6_Size
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 33;

                    ;% shabishiyan_P.GTS400PVsInitialization_P6
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 35;

                    ;% shabishiyan_P.GTS400PVsInitialization_P7_Size
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 38;

                    ;% shabishiyan_P.GTS400PVsInitialization_P7
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 40;

                    ;% shabishiyan_P.GTS400PVsInitialization_P8_Size
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 43;

                    ;% shabishiyan_P.GTS400PVsInitialization_P8
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 45;

                    ;% shabishiyan_P.GTS400PVsInitialization_P9_Size
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 48;

                    ;% shabishiyan_P.GTS400PVsInitialization_P9
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 50;

                    ;% shabishiyan_P.GTS400PVsInitialization_P10_Size
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 51;

                    ;% shabishiyan_P.GTS400PVsInitialization_P10
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 53;

                    ;% shabishiyan_P.GTS400PVsInitialization_P11_Size
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 54;

                    ;% shabishiyan_P.GTS400PVsInitialization_P11
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 56;

                    ;% shabishiyan_P.GTS400PVsInitialization_P12_Size
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 57;

                    ;% shabishiyan_P.GTS400PVsInitialization_P12
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 59;

                    ;% shabishiyan_P.GTS400PVsInitialization_P13_Size
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 60;

                    ;% shabishiyan_P.GTS400PVsInitialization_P13
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 62;

                    ;% shabishiyan_P.GTS400PVsInitialization_P14_Size
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 63;

                    ;% shabishiyan_P.GTS400PVsInitialization_P14
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 65;

                    ;% shabishiyan_P.GTS400PVsInitialization_P15_Size
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 66;

                    ;% shabishiyan_P.GTS400PVsInitialization_P15
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 68;

                    ;% shabishiyan_P.GTS400PVsInitialization_P16_Size
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 69;

                    ;% shabishiyan_P.GTS400PVsInitialization_P16
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 71;

                    ;% shabishiyan_P.GTS400PVsInitialization_P17_Size
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 72;

                    ;% shabishiyan_P.GTS400PVsInitialization_P17
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 74;

                    ;% shabishiyan_P.Constant2_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 75;

                    ;% shabishiyan_P.TmpRTBAtSum3Inport1_InitialCondition
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 76;

                    ;% shabishiyan_P.GTSGetPos_P1_Size
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 77;

                    ;% shabishiyan_P.GTSGetPos_P1
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 79;

                    ;% shabishiyan_P.PosEncoder_Gain
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 80;

                    ;% shabishiyan_P.Integrator_IC
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 81;

                    ;% shabishiyan_P.C_Gain
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 82;

                    ;% shabishiyan_P.AngleRef1_Value
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 90;

                    ;% shabishiyan_P.TmpRTBAtSum4Inport1_InitialCondition
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 91;

                    ;% shabishiyan_P.GTSGetPos1_P1_Size
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 92;

                    ;% shabishiyan_P.GTSGetPos1_P1
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 94;

                    ;% shabishiyan_P.AngleEncoder_Gain
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 95;

                    ;% shabishiyan_P.AngleRef_Value
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 96;

                    ;% shabishiyan_P.PosRef_Value
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 97;

                    ;% shabishiyan_P.A_Gain
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 98;

                    ;% shabishiyan_P.H_Gain
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 114;

                    ;% shabishiyan_P.K_Gain
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 122;

                    ;% shabishiyan_P.B_Gain
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 126;

                    ;% shabishiyan_P.Saturation_UpperSat
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 130;

                    ;% shabishiyan_P.Saturation_LowerSat
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 131;

                    ;% shabishiyan_P.Gain_Gain
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 132;

                    ;% shabishiyan_P.Constant1_Value_i
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 133;

                    ;% shabishiyan_P.EntryAngle_Value
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 134;

                    ;% shabishiyan_P.GTSSetAccVel_P1_Size
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 135;

                    ;% shabishiyan_P.GTSSetAccVel_P1
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 137;

                    ;% shabishiyan_P.GTSSetAccVel_P2_Size
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 138;

                    ;% shabishiyan_P.GTSSetAccVel_P2
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 140;

                    ;% shabishiyan_P.GTSSetAccVel_P3_Size
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 141;

                    ;% shabishiyan_P.GTSSetAccVel_P3
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 143;

                    ;% shabishiyan_P.GTSSetAccVel_P4_Size
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 144;

                    ;% shabishiyan_P.GTSSetAccVel_P4
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 146;

                    ;% shabishiyan_P.AccCof_Gain
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 147;

                    ;% shabishiyan_P.VelCof_Gain
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 148;

                    ;% shabishiyan_P.StopAngle_Value
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 149;

                    ;% shabishiyan_P.WhiteNoise_Mean
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 150;

                    ;% shabishiyan_P.WhiteNoise_StdDev
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 151;

                    ;% shabishiyan_P.WhiteNoise_Mean_l
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 152;

                    ;% shabishiyan_P.WhiteNoise_StdDev_e
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 153;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% shabishiyan_P.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 82;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_P.ManualSwitch1_CurrentSetting
                    section.data(2).logicalSrcIdx = 83;
                    section.data(2).dtTransOffset = 1;

                    ;% shabishiyan_P.ManualSwitch2_CurrentSetting
                    section.data(3).logicalSrcIdx = 84;
                    section.data(3).dtTransOffset = 2;

                    ;% shabishiyan_P.ManualSwitch3_CurrentSetting
                    section.data(4).logicalSrcIdx = 85;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (shabishiyan_B)
        ;%
            section.nData     = 23;
            section.data(23)  = dumData; %prealloc

                    ;% shabishiyan_B.TmpRTBAtSum3Inport1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_B.GTSGetPos
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% shabishiyan_B.Sum3
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% shabishiyan_B.Sum6
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% shabishiyan_B.Integrator
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% shabishiyan_B.C
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% shabishiyan_B.TmpRTBAtSum4Inport1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% shabishiyan_B.GTSGetPos1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 11;

                    ;% shabishiyan_B.Sum4
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 12;

                    ;% shabishiyan_B.Sum5
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% shabishiyan_B.pipi2
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 14;

                    ;% shabishiyan_B.Sum
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 15;

                    ;% shabishiyan_B.pipi1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 16;

                    ;% shabishiyan_B.Sum1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 17;

                    ;% shabishiyan_B.ManualSwitch
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 18;

                    ;% shabishiyan_B.Add
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 19;

                    ;% shabishiyan_B.Sum1_k
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 23;

                    ;% shabishiyan_B.pipi
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 24;

                    ;% shabishiyan_B.AccCof
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 25;

                    ;% shabishiyan_B.VelCof
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 26;

                    ;% shabishiyan_B.Constant
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 27;

                    ;% shabishiyan_B.In1
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 28;

                    ;% shabishiyan_B.In2
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% shabishiyan_B.RelationalOperator1
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_B.LogicalOperator3
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (shabishiyan_DW)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% shabishiyan_DW.TmpRTBAtSum3Inport1_Buffer0
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_DW.TmpRTBAtSum4Inport1_Buffer0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% shabishiyan_DW.TimeStampA
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% shabishiyan_DW.LastUAtTimeA
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% shabishiyan_DW.TimeStampB
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% shabishiyan_DW.LastUAtTimeB
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% shabishiyan_DW.TimeStampA_i
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% shabishiyan_DW.LastUAtTimeA_f
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% shabishiyan_DW.TimeStampB_a
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% shabishiyan_DW.LastUAtTimeB_d
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% shabishiyan_DW.NextOutput
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% shabishiyan_DW.NextOutput_j
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% shabishiyan_DW.GTS400PVsInitialization_PWORK
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_DW.GTSGetPos_PWORK
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% shabishiyan_DW.GTSGetPos1_PWORK
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% shabishiyan_DW.AP_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% shabishiyan_DW.Angle_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 5;

                    ;% shabishiyan_DW.Pos_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 6;

                    ;% shabishiyan_DW.real_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 7;

                    ;% shabishiyan_DW.state_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 9;

                    ;% shabishiyan_DW.GTSSetAccVel_PWORK
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 10;

                    ;% shabishiyan_DW.Scope_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 11;

                    ;% shabishiyan_DW.Scope1_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 22;
                    section.data(11).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% shabishiyan_DW.RandSeed
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_DW.RandSeed_h
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% shabishiyan_DW.TriggeredSubsystem_SubsysRanBC
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% shabishiyan_DW.EnabledSubsystem1_SubsysRanBC
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% shabishiyan_DW.EnabledSubsystem1_MODE
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1823205528;
    targMap.checksum1 = 1361776196;
    targMap.checksum2 = 77534385;
    targMap.checksum3 = 4207340635;

