
[Rainmeter]
Update=1000
BackgroundMode=2
SolidColor=#BackgroundColor#

[Metadata]
Name=GlobalSettings
Author=LexyGuru
Information=Global default values for all meters.
License=Creative Commons BY-NC-SA 3.0
Version=1.0.1


;-----------------------------
;-----------------------------

[Variables]
colorRed=245,80,80,220
colorRedDim=245,50,50,140
colorPurple=220,80,220,220
colorBlue=100,150,250,220
colorBlueDim=100,150,250,140
colorBlueSolid=100,150,250,255
colorBlueLite=180,220,255,220
colorGreen=100,250,100,220
colorGreenDim=100,250,100,140
colorWhite=255,255,255,220
colorWhiteLit=255,255,255,170
colorWhiteDim=255,255,255,150
colorWhiteDimLow=255,255,255,100
colorWhiteDimMin=255,255,255,50
colorYellow=235,170,0,220
colorYellowLiteHi=255,255,180,220
colorYellowLite=255,225,115,220
colorYellowLiteLow=255,200,50,220
colorCyan=55,255,255,220
colorCyanDim=55,255,255,160
colorClear=0,0,0,0
colorBlack=0,0,0,220
colorGray=0,0,0,100
;;;;;;colors = R,G,B,translucent
colorCore0=#colorWhite#
colorCore1=#colorBlueLite#
colorCore2=#colorWhite#
colorCore3=#colorBlueLite#
colorCore4=#colorWhite#
colorCore5=#colorBlueLite#
colorCore6=#colorWhite#
colorCore7=#colorBlueLite#
colorCore8=#colorWhite#
colorCore9=#colorBlueLite#
colorCore10=#colorWhite#
colorCore11=#colorBlueLite#

fontName=Trebuchet MS
textSizeMd=12
textSize=8

All-in-OneSkinLoc=RainmeterWin10-master\HWiNFO\All-in-One
NetSkinLoc=RainmeterWin10-master\HWiNFO\Network
NetConfigSkinLoc=RainmeterWin10-master\HWiNFO\Network\config
CPUmemSkinLoc=RainmeterWin10-master\HWiNFO\CPUmem
PerfConfigSkinLoc=RainmeterWin10-master\HWiNFO\perfconfig
DiskConfigSkinLoc=RainmeterWin10-master\HWiNFO\DiskConfig
;GPUSkinLoc=RainmeterWin10-master\HWiNFO\GPU
;GPUConfigSkinLoc=RainmeterWin10-master\HWiNFO\GPU\config

BackgroundColor=0,0,0,75

meterScaleClock=1.0
meterScaleCPU=1
meterScaleNet=1.0
meterScaleDisk=1.0
meterScaleWx=1.0
meterScaleVolume=1.0
meterScaleGPU=1.0
meterScaleAll-in-One=1.0

CPU0MhzMeasureName=measureCPUfreq
CPU0colorMhzHWiNFOSelect=255,255,255,50
CPU0colorMhzPerfMonSelect=245,80,80,220
CPU0colorFanOffSelect=255,255,255,50
CPU0colorFanOnSelect=100,250,100,220
CPU0FanOnOffSelect=0

;GPUcolorFanRpmSelect=245,80,80,220
;GPUcolorFanPerSelect=255,255,255,50
;GPUfanMeasureName=HWiNFOGPU0FanRpm
;GPUfanUOM=rpm
;GPUmemTotalMeasureName=HWiNFOGPU0MemMax
;; HWiNFOGPU0MemMax or HWiNFOGPU0MemMaxAMD
;GPUmemUsedMeasureName=HWiNFOGPU0MemUsed
;; HWiNFOGPU0Mem or HWiNFOGPU0MemUsedAMD
;GPUcolorAMDmemSelect=255,255,255,50
;GPUcolorNVmemSelect=100,250,100,220

NetId=0
netInMeasureName=measureNetInBits
netOutMeasureName=measureNetOutBits
netUOM=b
NetColorBits=255,255,255,50
NetColorBytes=0,0,0,0
NetHideExt=0
NetHideExtText=1
NetColorHideExt=0,0,0,0
NetColorShowExt=255,255,255,50


Disk1SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter1
Disk2SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter2
Disk3SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter3
Disk4SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter4
Disk5SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter5
Disk6SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter6
Disk7SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter7
Disk8SkinLoc=RainmeterWin10-master\HWiNFO\DiskMeter8

DiskColor1tempOffSelect=255,255,255,50
DiskColor1tempOnSelect=100,250,100,220
DiskColor2tempOffSelect=245,80,80,220
DiskColor2tempOnSelect=255,255,255,50
DiskColor3tempOffSelect=245,80,80,220
DiskColor3tempOnSelect=255,255,255,50
DiskColor4tempOffSelect=245,80,80,220
DiskColor4tempOnSelect=255,255,255,50
DiskColor5tempOffSelect=245,80,80,220
DiskColor5tempOnSelect=255,255,255,50
DiskColor6tempOffSelect=245,80,80,220
DiskColor6tempOnSelect=255,255,255,50
DiskColor7tempOffSelect=245,80,80,220
DiskColor7tempOnSelect=255,255,255,50
DiskColor8tempOffSelect=245,80,80,220
DiskColor8tempOnSelect=255,255,255,50

1_DriveTempOnOff=0
2_DriveTempOnOff=1
3_DriveTempOnOff=1
4_DriveTempOnOff=1
5_DriveTempOnOff=1
6_DriveTempOnOff=1
7_DriveTempOnOff=1
8_DriveTempOnOff=1

1_DriveLetter=C
2_DriveLetter=D
3_DriveLetter=E
4_DriveLetter=F
5_DriveLetter=G
6_DriveLetter=H
7_DriveLetter=I
8_DriveLetter=J



;-----------------------------
;-----------------------------

[styleLeftTextMed]
StringAlign=Left
;StringCase=Upper
StringStyle=Bold
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#colorWhite#
FontFace=#fontName#
FontSize=#textSizeMd#
AntiAlias=1
ClipString=1

[styleRightTextMed]
StringAlign=Right
;StringCase=Upper
StringStyle=Bold
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#colorWhite#
FontFace=#fontName#
FontSize=#textSizeMd#
AntiAlias=1
ClipString=1

[styleCenterTextMed]
StringAlign=Center
StringCase=Upper
StringStyle=Bold
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#colorWhite#
FontFace=#fontName#
FontSize=#textSizeMd#
AntiAlias=1
ClipString=1

;-------

[styleLeftText]
StringAlign=Left
StringCase=None
StringStyle=Bold
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#colorWhite#
FontFace=#fontName#
FontSize=#textSize#
AntiAlias=1
ClipString=1

[styleLeftTextSmall]
StringAlign=Left
StringCase=None
StringStyle=Normal
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#colorWhite#
FontFace=Segoe UI
FontSize=7
AntiAlias=1
ClipString=1

;-------

[styleRightText]
StringAlign=Right
StringCase=None
StringStyle=Bold
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#colorWhite#
FontFace=#fontName#
FontSize=#textSize#
AntiAlias=1
ClipString=1

[styleRightTextSmall]
StringAlign=Right
StringCase=None
StringStyle=Normal
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#colorWhite#
FontFace=Segoe UI
FontSize=7
AntiAlias=1
ClipString=1

;-------

[styleBarYellow]
BarColor=#colorYellow#
BarOrientation=HORIZONTAL
SolidColor=#colorWhiteDimMin#

[styleBarRed]
BarColor=#colorRed#
BarOrientation=HORIZONTAL
SolidColor=#colorWhiteDimMin#

[styleBarBlue]
BarColor=#colorBlue#
BarOrientation=HORIZONTAL
SolidColor=#colorWhiteDimMin#

;-----------------------------
;-----------------------------

