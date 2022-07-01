# STM32F103BasicLibrary
## 总共包含五种文件夹，文件夹已全部上传
## 编码格式均为UTF-8
---

- CMSIS文件夹
- Library文件夹
- PATH文件夹
- User文件夹
- Startup文件夹
- System文件夹

---
### 具体文件含义也可到各自文件夹内部的md文件查看，此处也将列出
////////////////////////////////////////////////////////////////

# //System文件夹解释//

---
## Comopenmv文件
- Openmv通信文件
#### 内部文件
- Comopenmv.c
- Comopenmv.h
#### 前置文件
- stm32f10x.h 
---

---
## delay文件
- 不精确的延时函数
#### 内部文件
- delay.c
- delay.h
#### 前置文件
- stm32f10x.h
- delay.h
---

---
## encoder文件
- 霍尔编码器配置文件
#### 内部文件
- encoder.c --> 编码器TIM初始化
- encoder.h --> 基本不用更改
#### 前置文件： 
 - sys.h
---

---
## GPIO文件
- 对GPIO进行初始化
- 在头文件中开放define即可
#### 内部文件
- GPIO.c
- GPIO.h
#### 前置文件
- stm32f10x.h
---

---
## linewalking文件
- 巡线文件
#### 内部文件
- linewalking.c
- linewalking.h
#### 前置文件
- sys.h
- motor.h
- delay.h
---

---
## miscell文件
- 部分自写函数存储
#### 内部文件
- Miscell.c
- Miscell.h
#### 前置文件
- stm32f10x.h
---

---
## motor文件
- 电机运动控制函数
#### 内部文件
- motor.c
- motor.h
#### 前置文件
- sys.h
---

---
## mpu6050文件
- mpu6050控制文件
#### 内部文件
- mpu_i2c.c
- mpu_i2c.h
- mpu6050.c
- mpu6050.h
#### 前置文件
- 
---

---
## oled文件

#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## PID文件

#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## PID_Motor文件

#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## Precise_delay文件
- 精确的延时函数
- 使用delay_time(int times)函数即可进行给定ms的延时
#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## PWM文件

#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## sys文件

#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## SystickTimer文件

#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## usart文件

#### 内部文件
- 
- 
#### 前置文件
- 
---

---
## VOFA文件
- 使用Vofa上位机进行调参时所使用的通讯接口。

>通过使用
> - vofa1(float one)
> - vofa2(float one,float two)
> - vofa3(float one,float two,float three)
> - vofa4(float one,float two,float three,float four)

- 此处仅列出四项，可以通过修改源码进行添加
#### 内部文件
- 
- 
#### 前置文件
- 
---

## 