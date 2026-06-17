/*
 * i2c_master.h
 *
 * Created: 2025/5/18 19:41:11
 *  Author: dxydu
 */ 


#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include <stdint.h>

// Define I2C Clock speed (typically 100kHz or 400kHz)
#define I2C_CLOCK_SPEED 100000

// I2C Status Codes
#define I2C_OK           0
#define I2C_ERROR        1
#define I2C_NACK         2

// I2C Master initialization
void I2C_MasterInit(void);

// Start I2C communication
void I2C_MasterStart(void);

// Stop I2C communication
void I2C_MasterStop(void);

// Send a byte of data to the I2C bus
uint8_t I2C_MasterWrite(uint8_t data);

// Receive a byte of data from the I2C bus
uint8_t I2C_MasterRead(void);

// Send an ACK signal to acknowledge data reception
void I2C_MasterAck(void);

// Send a NACK signal to indicate the end of data reception
void I2C_MasterNack(void);

// Write a data byte to a specific I2C address
uint8_t I2C_Write(uint8_t address, uint8_t data);

// Read a data byte from a specific I2C address
uint8_t I2C_Read(uint8_t address);

// Helper function to check if I2C bus is idle
uint8_t I2C_BusIdle(void);

#endif // I2C_MASTER_H
