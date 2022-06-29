# STM32F103BasicLibrary
## 总共包含五种文件夹，文件夹已全部上传
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
## VOFA文件
使用Vofa上位机进行调参时所使用的通讯接口。

通过使用
- vofa1(float one)
- vofa2(float one,float two)
- vofa3(float one,float two,float three)
- vofa4(float one,float two,float three,float four)

此处仅列出四项，可以通过修改源码进行添加

---
---
## delay文件
- 不精确的延时函数
---