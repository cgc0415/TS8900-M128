# TS8900-M128
ATMega128单片机程序

## ICCAVR工程创建
1、Project->New，输入工程名（只能使用字母、数字、下划线）
2、鼠标右键点击页面右侧的Project->Files，添加源代码文件
3、打开Project->Options，在Device Configuration中设置芯片类型为：ATMega-128(Please see Notes)，如果不设置该项，可能导致编译出的.hex文件无法正确运行。
4、编译工程