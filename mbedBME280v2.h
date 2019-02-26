#ifndef BME280_H
#define BME280_H

#include "mbed.h"

#if(defined(TARGET_KL25Z) || defined(TARGET_K64F))

//    #define BME280i2cLOWLEVEL   1           //if the use of low-level I2C routines is needed
//    #warning "BME280 using low level I2C routines"
    
#endif


#define SEA_PRESS               1013.25             //default sea level pressure level in mb
//#define KNOWNALT                327.0               //default known altitude in feet
#define METERS_FEET             3.2808399
#define FEET_METERS             0.3048006
#define MB_INHG_DOUBLE          0.02952998751
#define INHG_MB_DOUBLE          33.8638815767
#define DEGC_DEGF_FLOAT         9.0 / 5.0 + 32.0
#define DEGC_DEGF_INT           9 / 5 + 32

#define BME280_WADDR                        0x77  //i2c address write mode (CSBpin = 0);
#define BME280_RADDR                        0x77  //i2c address read mode

//Register names:
#define BME280_DIG_T1_LSB_REG			0x88
#define BME280_DIG_T1_MSB_REG			0x89
#define BME280_DIG_T2_LSB_REG			0x8A
#define BME280_DIG_T2_MSB_REG			0x8B
#define BME280_DIG_T3_LSB_REG			0x8C
#define BME280_DIG_T3_MSB_REG			0x8D
#define BME280_DIG_P1_LSB_REG			0x8E
#define BME280_DIG_P1_MSB_REG			0x8F
#define BME280_DIG_P2_LSB_REG			0x90
#define BME280_DIG_P2_MSB_REG			0x91
#define BME280_DIG_P3_LSB_REG			0x92
#define BME280_DIG_P3_MSB_REG			0x93
#define BME280_DIG_P4_LSB_REG			0x94
#define BME280_DIG_P4_MSB_REG			0x95
#define BME280_DIG_P5_LSB_REG			0x96
#define BME280_DIG_P5_MSB_REG			0x97
#define BME280_DIG_P6_LSB_REG			0x98
#define BME280_DIG_P6_MSB_REG			0x99
#define BME280_DIG_P7_LSB_REG			0x9A
#define BME280_DIG_P7_MSB_REG			0x9B
#define BME280_DIG_P8_LSB_REG			0x9C
#define BME280_DIG_P8_MSB_REG			0x9D
#define BME280_DIG_P9_LSB_REG			0x9E
#define BME280_DIG_P9_MSB_REG			0x9F
#define BME280_DIG_H1_REG				0xA1
#define BME280_CHIP_ID_REG				0xD0 //Chip ID
#define BME280_RST_REG					0xE0 //Softreset Reg
#define BME280_DIG_H2_LSB_REG			0xE1
#define BME280_DIG_H2_MSB_REG			0xE2
#define BME280_DIG_H3_REG				0xE3
#define BME280_DIG_H4_MSB_REG			0xE4
#define BME280_DIG_H4_LSB_REG			0xE5
#define BME280_DIG_H5_MSB_REG			0xE6
#define BME280_DIG_H6_REG				0xE7
#define BME280_CTRL_HUMIDITY_REG		0xF2 //Ctrl Humidity Reg
#define BME280_STAT_REG					0xF3 //Status Reg
#define BME280_CTRL_MEAS_REG			0xF4 //Ctrl Measure Reg
#define BME280_CONFIG_REG				0xF5 //Configuration Reg
#define BME280_PRESSURE_MSB_REG			0xF7 //Pressure MSB
#define BME280_PRESSURE_LSB_REG			0xF8 //Pressure LSB
#define BME280_PRESSURE_XLSB_REG		0xF9 //Pressure XLSB
#define BME280_TEMPERATURE_MSB_REG		0xFA //Temperature MSB
#define BME280_TEMPERATURE_LSB_REG		0xFB //Temperature LSB
#define BME280_TEMPERATURE_XLSB_REG		0xFC //Temperature XLSB
#define BME280_HUMIDITY_MSB_REG			0xFD //Humidity MSB
#define BME280_HUMIDITY_LSB_REG			0xFE //Humidity LSB

// Status register bits
#define BME280_STATUS_BUSY                  0x08
#define BME280_STATUS_UNKNOWN               0x04
#define BME280_STATUS_IMUPDATE              0x01

#define BME280_RESET_VALUE                  0xB6

// Config register equates
#define BME280_OVERSAMPLE_SKIP              0
#define BME280_OVERSAMPLE_x1                1
#define BME280_OVERSAMPLE_x2                2
#define BME280_OVERSAMPLE_x4                3
#define BME280_OVERSAMPLE_x8                4
#define BME280_OVERSAMPLE_x16               5

#define BME280_TEMP_OVERSAMPLE              BME280_OVERSAMPLE_x1 //was x2 
#define BME280_PRESS_OVERSAMPLE             BME280_OVERSAMPLE_x1 //was x4
#define BME280_HUM_OVERSAMPLE               BME280_OVERSAMPLE_x1 //was x2

#define BME280_MODE_SLEEP                   0
#define BME280_MODE_FORCED                  1
#define BME280_MODE_NORMAL                  3

#define BME280_STANDBY_0m5                  0
#define BME280_STANDBY_62m5                 1
#define BME280_STANDBY_125m                 2
#define BME280_STANDBY_250m                 3
#define BME280_STANDBY_500m                 4
#define BME280_STANDBY_1000m                5
#define BME280_STANDBY_10m                  6
#define BME280_STANDBY_20m                  7

#define BME280_FILTER_OFF                   0
#define BME280_FILTER_2                     1
#define BME280_FILTER_4                     2
#define BME280_FILTER_8                     3
#define BME280_FILTER_16                    4

//osrs_t(7..5), osrs_p(4..2), mode(1..0)
#define BME280_CTRL_MEAS_REG_DATA           ((BME280_TEMP_OVERSAMPLE << 5) | (BME280_PRESS_OVERSAMPLE << 2) | BME280_MODE_NORMAL)
//0(7..3), osrs_h(2..0)
#define BME280_CTRL_HUMIDITY_REG_DATA       ((BME280_HUM_OVERSAMPLE))
//sb(7..5), filter(4..2), 0(1), spl3w_en(0)
#define BME280_CONFIG_REG_DATA              ((BME280_STANDBY_1000m << 5) | (BME280_FILTER_OFF << 2)) //was FILTER_4

//Until it is understood why data cannot be raed out of BME280 right after BUSY goes false, the 
//defines below introduce a variable delay in main(), based on sb bits used.
// example: wait_ms(BME280_MAIN_WAIT);  must be put between pth.getBmeRawData(bmed_struct); accesses 
#if   ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_0m5)
#define BME280_MAIN_WAIT                           100
#elif ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_62m5)
#define BME280_MAIN_WAIT                           60
#elif ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_125m)
#define BME280_MAIN_WAIT                           120
#elif ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_250m)
#define BME280_MAIN_WAIT                           240
#elif ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_500m)
#define BME280_MAIN_WAIT                           100
#elif ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_1000m)
#define BME280_MAIN_WAIT                           500
#elif ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_10m)
#define BME280_MAIN_WAIT                           50
#elif ((BME280_CONFIG_REG_DATA >> 5) == BME280_STANDBY_20m)
#define BME280_MAIN_WAIT                           59
#endif


    /** 
     * Create bme280 controller class
     *
     * @param bme280 class
     *
     */
class bme280 {

public:

    /** 
     * Public data structure for CME280 correction values.
     * 
    **/
    typedef struct {
        uint16_t dig_T1;    /*!< calibration parameter -> Temp T1 */  
        int16_t  dig_T2;    /*!< calibration parameter -> Temp T2 */  
        int16_t  dig_T3;    /*!< calibration parameter -> Temp T3 */
          
        uint16_t dig_P1;    /*!< calibration parameter -> Press P1 */  
        int16_t  dig_P2;    /*!< calibration parameter -> Press P2 */  
        int16_t  dig_P3;    /*!< calibration parameter -> Press P3 */  
        int16_t  dig_P4;    /*!< calibration parameter -> Press P4 */  
        int16_t  dig_P5;    /*!< calibration parameter -> Press P5 */  
        int16_t  dig_P6;    /*!< calibration parameter -> Press P6 */  
        int16_t  dig_P7;    /*!< calibration parameter -> Press P7 */  
        int16_t  dig_P8;    /*!< calibration parameter -> Press P8 */  
        int16_t  dig_P9;    /*!< calibration parameter -> Press P9 */  
    
        uint8_t  dig_H1;    /*!< calibration parameter -> Hum H1 */  
        int16_t  dig_H2;    /*!< calibration parameter -> Hum H2 */  
        uint8_t  dig_H3;    /*!< calibration parameter -> Hum H3 */  
        int16_t  dig_H4;    /*!< calibration parameter -> Hum H4 */  
        int16_t  dig_H5;    /*!< calibration parameter -> Hum H5 */  
        int8_t   dig_H6;    /*!< calibration parameter -> Hum H6 */  
    
        uint32_t t_fine;    /*!< scratch T_FINE */
         
        uint8_t  ctrl_hum_reg;  /*!< config -> hum */
        uint8_t  ctrl_meas_reg; /*!< config -> temp press mode */
        uint8_t  config_reg;    /*!< config -> delay filter spi3w */ 
    } bme_cal;
         
    /** 
     * Public data structure to obtain CME280 data.
     * 
    **/
    typedef struct {
        int raw_temp;       /*!< raw temperature reading, 20 bits */
        int raw_baro;       /*!< raw pressure reading, 20 bits */
        int raw_hum;        /*!< raw humidity reading, 16 bits */
        int corr_temp;      /*!< corrected temperature as integer*/
        int64_t corr_baro;  /*!< corrected pressure as integer */
        uint32_t corr_hum;  /*!< corrected humidity as integer */
        double bme_temp;    /*!< corrected temperature as a float */
        double bme_baro;    /*!< corrected pressure as a float */
        double bme_hum;     /*!< corrected humidity as a float */
    } bme_data;

    /** 
     * Public enum for selecting polarity of I2C address pin.
     *
     * - CSB pin = 0, user set I2C address to 0x77
     * - CSB pin = 1, user set I2C address to 0xEE
     * 
    **/    
    enum CSBpolarity {
        CSBpin_0,  //CSB pin is grounded, I2C address is 0x77 and 0xED
        CSBpin_1,  //CSB pin is tied to Vdd, I2C address is 0xEE and 0xEF
    };

    /** 
     * Create a BME280 object using the specified I2C object
     *   - User defined use of the CSB pin
     *   - CSB pin = 0, user set I2C address to 0x77
     *   - CSB pin = 1, user set I2C address to 0xEE 
     * @param sda - mbed I2C interface pin
     * @param scl - mbed I2C interface pin
     * @param bme280::CSBpin_0 - CSB pin tied to ground
     * @param bme280::CSBpin_1 - CSB pin tied to VDD
     */
    bme280(PinName sda, PinName scl, CSBpolarity CSBpin);

    /**
     * Destructor
     *
     * @param --none--
     */
    ~bme280();

    /** 
     * Get BME280 ID Register
     * 
     * @param --none--
     *
     * @return ID Register value
    */ 
    uint8_t getBmeID();

    /** 
     * Soft Reset the BME280
     * 
     * @param --none--
     *
     * @return ACK/NACK status
    */
    uint8_t resetBme();
    
    /** 
     * Get BME280 Status Register
     * 
     * @param --none--
     *
     * @return Status Register value
    */ 
    uint8_t getBmeStatus();

    /** 
     * Get BME280 Raw Data
     * 
     * @param pointer to struct bme_data
     *
     * @return Status Register value. Pass-thru from getBmeStatus()
     * @return raw data put into struct bme_data
    */ 
    uint8_t getBmeRawData(bme_data& bmed);

    /** 
     * Convert BME280 Raw Data using integer based routines
     * 
     * @param pointer to struct bme_data
     * @param pointer to struct bme_cal
     *
     * @return converted data put into struct bme_data
    */ 
    void convertBmeRawData(bme_data& bmed, bme_cal& bmec);

    /** 
     * Convert BME280 Raw Data using all floating routines
     * 
     * @param pointer to struct bme_data
     * @param pointer to struct bme_cal
     *
     * @return converted data put into struct bme_data
    */ 
    void convertBmeRawDataFloat(bme_data& bmed, bme_cal& bmec);
    
    /** 
     * Initialize the BME280. 
     * - Sets up the command registers
     * - Loads up the calibration data
     * 
     * @param pointer to struct bme_data
     *
     * @return 0
    */  
    uint8_t initBme(bme_cal& bmec);
    
    /** 
     * Corrected altitude (feet) from barometer at seal level (mB)
     * 
     * @param pointer to struct bme_data
     * @param pressure at sea level (in mB)
     *
     * @return corrected altimeter (in feet)
    */ 
    float getAltitudeFT(bme_data& bmed, float sea_pressure);
    
    /** 
     * Altitude corrected barometer (feet)
     * 
     * @param pointer to struct bme_data
     * @param known_alt in feet
     *
     * @return corrected barometer
    */
    float getSeaLevelBaroFT(bme_data& bmed, float known_alt);
    
    /** 
     * Altitude corrected barometer (meters)
     * 
     * @param pointer to struct bme_data
     * @param known_alt in meters
     *
     * @return corrected barometer
    */    
    float getSeaLevelBaroM(bme_data& bmed, float known_alt);

    /** 
     * Return the dew point based on T & H. Slower but more accurate.
     * 
     * @param pointer to struct bme_data
     *
     * @return dew point in degrees C
    */  
    float getDewPt(bme_data& bmed);

    /** 
     * Return the dew point based on T & H. Faster but less accurate.
     * 
     * @param pointer to struct bme_data
     *
     * @return dew point in degrees C
    */ 
    float getDewPtFast(bme_data& bmed);
    
private:
#if not defined  BMEi2cLOWLEVEL
    char bme280Buffer[32];
#endif
    char i2cWAddr;
    char i2cRAddr;
    int _i2c_start(uint8_t i2c_addr);
    void _i2c_stop();
    uint8_t _i2c_write(uint8_t data);
    uint8_t _i2c_readACK();
    uint8_t _i2c_readNACK();
  
protected:
    I2C     _i2c;
}; 
#endif