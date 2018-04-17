

[measureUpTime]
Measure=UpTime
Format="%4!i!d %3!i!:%2!02i!:%1!02i!"

[measureCPUfreq]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=Processor Information
PerfMonCounter=Processor Frequency
PerfMonInstance=0,0
PerfMonDifference=0

[measureCPUfreqCheck]
Measure=Calc
UpdateDivider=-1
IfCondition=measureCPUfreq < 1
IfTrueAction=[!HideMeter "meterCPUfreq"][!DisableMeasure "measureCPUfreq"][!ShowMeter "meterCPUfreqStatic"]

[measureCPUfreqStatic]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=~MHz
UpdateDivider=-1

[measureCPUModelStatic]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=HARDWARE\DESCRIPTION\System\CentralProcessor\0
RegValue=ProcessorNameString
RegExpSubstitute=1
Substitute="\([^(]*\)":""," CPU ":" "," Processor ":" ","  *":" "
UpdateDivider=-1

[measureCPU0]
Measure=CPU
Processor=0


;------------------------------------
;------------------------------------


[meterOpenPerfConfigSkin]
Meter=String
X=160
Y=5
H=14
W=13
SolidColor=#colorGray#
FontColor=#colorWhiteDim#
StringStyle=Bold
FontSize=14
AntiAlias=1
Text=*
UpdateDivider=-1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterUptimeLabel]
Meter=String
MeterStyle=styleLeftText
X=15
Y=10
W=60
H=18
Text=Uptime
UpdateDivider=-1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterUptime]
Meter=String
MeterStyle=styleRightText
MeasureName=measureUpTime
X=155
Y=0r
W=80
H=14
Text=%1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

;--------

[MeterCPUHistogram]
Meter=Histogram
MeasureName=MeasureCPU0
X=10
Y=15r
W=#HistogramWidth#
H=30
PrimaryColor=#colorBlue#
SolidColor=#colorGray#
AntiAlias=1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterCPUfreq]
Meter=String
MeasureName=#CPU0MhzMeasureName#
MeterStyle=styleRightTextSmall
X=160r
Y=0r
W=60
H=14
Text=%1 MHz
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterCPUfreqStatic]
Meter=String
MeasureName=measureCPUfreqStatic
MeterStyle=styleRightTextSmall
X=0r
Y=0r
W=60
H=14
Text=%1 MHz
UpdateDivider=-1
Hidden=1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterLabelCPUHistogram]
Meter=String
MeterStyle=styleLeftTextSmall
X=10
Y=0r
W=60
H=14
Text=CPU usage
UpdateDivider=-1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

;------------------------------------
;------------------------------------

[meterCPUuseageMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([MeterCPUHistogram:X] * #meterScaleCPU#)
Y=([MeterCPUHistogram:Y] * #meterScaleCPU#)
W=([MeterCPUHistogram:W] * #meterScaleCPU#)
H=([MeterCPUHistogram:H] * #meterScaleCPU#)
LeftMouseUpAction=[perfmon.exe /res]
UpdateDivider=-1

[meterCPUtooltipMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterLabelCPUHistogram:X] * #meterScaleCPU#)
Y=([meterLabelCPUHistogram:Y] * #meterScaleCPU#)
W=([meterLabelCPUHistogram:W] * #meterScaleCPU#)
H=([meterLabelCPUHistogram:H] * #meterScaleCPU#)
ToolTipText=[measureCPUModelStatic]
UpdateDivider=-1
DynamicVariables=1

[meterPerfSettingsMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterOpenPerfConfigSkin:X] * #meterScaleCPU#)
Y=([meterOpenPerfConfigSkin:Y] * #meterScaleCPU#)
W=([meterOpenPerfConfigSkin:W] * #meterScaleCPU#)
H=([meterOpenPerfConfigSkin:H] * #meterScaleCPU#)
ToolTipText=Settings
LeftMouseUpAction=[!ToggleConfig #PerfConfigSkinLoc# "perfconfig.ini"]
UpdateDivider=-1


;------------------------------------

