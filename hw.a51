?PR?HONGWAI SEGMENT CODE
PUBLIC HONGWAI;     
RSEG ?PR?HONGWAI; 能够让c语言调用汇编函数
	
HONGWAI:
    JNB    P3.2,IR        ;遥控扫描
    LJMP   HONGWAI          ;在正常无遥控信号时，一体化红外接收头输出是高电平，程序一直在循环。
 
;=================================================
;   解码程序
IR: 
    ;以下对遥控信号的9000微秒的初始低电平信号的识别
    MOV    R4,#10
IR_SB:
    ACALL  DELAY882        ;调用882微秒延时子程序
    JB     P3.2,IR_ERROR   ;延时882微秒后判断P2.2脚是否出现高电平如果有就退出解码程序
    DJNZ   R4,IR_SB        ;重复10次，目的是检测在8820微秒内如果出现高电平就退出解码程序
 
    ;识别连发码，和跳过4.5ma的高电平。
    JNB     P3.2, $         ;等待高电平避开9毫秒低电平引导脉冲
    ACALL  DELAY2400
    JNB     P3.2,IR_Rp    ;这里为低电平，认为是连发码信号，见图６。
    ACALL  DELAY2400      ;延时4.74毫秒避开4.5毫秒的结果码
	;上述是识别数据前的信号
 
    ;以下32数据码的读取　，０和１的识别　请看图2
    MOV     R1,#1AH        ;设定1AH为起始RAM区
    MOV     R2,#4 
IR_4BYTE: 
    MOV     R3,#8
IR_8BIT:   
    JNB     P3.2,$         ;等待地址码第一位的高电平信号
    LCALL  DELAY882        ;高电平开始后用882微秒的时间尺去判断信号此时的高低电平状态
    MOV    C,P3.2          ;将P2.2引脚此时的电平状态0或1存入C中
    JNC     IR_8BIT_0      ;如果为0就跳转到IR_8BIT_0
    LCALL  DELAY1000
IR_8BIT_0: 
    MOV    A,@R1           ;将R1中地址的给A
    RRC    A               ;将C中的值0或1移入A中的最低位
    MOV    @R1,A           ;将A中的数暂时存放在R1中
    DJNZ   R3,IR_8BIT      ;接收地址码的高8位
    INC    R1              ;对R1中的值加1，换下一个RAM
    DJNZ   R2,IR_4BYTE     ;接收完16位地址码和8位数据码和8位数据，
                           ;存放在1AH/1BH/1CH/1DH的RAM中
     ;解码成功
    JMP    IR_GOTO
 
IR_Rp:
    ;这里为重复码执行处
    ;按住遥控按键时，每过108ms就到这里来
    JMP    IR_GOTO
 
IR_ERROR:
    ;错语退出
    LJMP   HONGWAI ;退出解码子程序
 
;=================================================
;遥控执行部份
IR_GOTO:
    ;这里还要判断1AH和1BH　两个系统码或用户码，用于识别不同的遥控器
    ;MOV   A,1AH
    ;CJNE  A,#xxH,IR_ERROR   ;用户码１不对则退出
    ;MOV   A,1BH
    ;CJNE  A,#xxH,IR_ERROR   ;用户码２不对则退出
 
 
 
    ;判断两个数据码是否相反
    MOV    A,1CH
    CPL    A
    CJNE   A,1DH,IR_ERROR    ;两个数据码不相反则退出
    ;遥控执行部份
    ;MOV   A,1DH             ;判断对应按键
    ;CJNE  A,#xxH,$+6
    ;LJMP  -à跳到对应按键执行处
    ;CJNE  A,#xxH,$+6
    ;LJMP  -à跳到对应按键执行处
    ;.
    MOV     P2,1DH         ;将按键的键值传递到p2口，方便主函数判断

 
    ;清除遥控值使连按失效
    MOV    1AH,#00H
    MOV    1BH,#00H
    MOV    1CH,#00H
    MOV    1DH,#00H 
    RET
	
;=================================================
; 延时子程序
;=============================882
;1.085x ((202x4)+5)=882
DELAY882:   
    MOV R7,#202
DELAY882_A:
    NOP
    NOP
    DJNZ   R7,DELAY882_A
RET
 
;=============================1000
;1.085x ((229x4)+5)=999.285
DELAY1000: 
    MOV R7,#229
DELAY1000_A:
    NOP
    NOP
    DJNZ   R7,DELAY1000_A
RET
;=============================2400
;1.085x ((245x9)+5)=2397.85
DELAY2400:   
    MOV R7,#245
DELAY2400_A:
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    DJNZ R7,DELAY2400_A
RET
END