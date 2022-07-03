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
- oled屏幕文件
#### 内部文件
- oled.c
- oled.h
- oledfont.h
#### 前置文件
- 
---

---
## PID文件
- PID文件
#### 内部文件
- PID.c
- PID.h
#### 前置文件
- 
---

---
## PID_Motor文件
- PID控制下电机运动函数
#### 内部文件
- PID_Motor.c
- PID_Motor.h
#### 前置文件
- 
---

---
## Precise_delay文件
- 精确的延时函数
- 使用delay_time(int times)函数即可进行给定ms的延时
#### 内部文件
- Precise_delay.c
- Precise_delay.h
#### 前置文件
- 
---

---
## PWM文件
- PWM配置文件
#### 内部文件
- pwm.c
- pwm.h
#### 前置文件
- stm32f10x.h
---

---
## sys文件
- sys函数
#### 内部文件
- sys.c
- sys.h
#### 前置文件
- 
---

---
## SystickTimer文件
- 系统滴答计时器初始化
#### 内部文件
- SystickTimer.c
- SystickTimer.h
#### 前置文件
- 
---

---
## usart文件
- usart函数
#### 内部文件
- usart.c
- usart.h
#### 前置文件
- sys.h
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
- VOFA.c
- VOFa.h
#### 前置文件
- 
---

## 