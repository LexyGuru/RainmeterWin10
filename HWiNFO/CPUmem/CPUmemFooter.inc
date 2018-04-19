

;------------------------------------

[measureRAM]
Measure=PhysicalMemory
UpdateDivider=5

[measureRAMtotal]
Measure=PhysicalMemory
UpdateDivider=3600
Total=1

[measureRAMavail]
Measure=PhysicalMemory
InvertMeasure=1
UpdateDivider=5

[measureRAMavailScale]
Measure=Script
ScriptFile=#@#/MinPrecision.lua
InputValue=[measureRAMavail]
Precision=3
Factor=1

;------------------------------------

[measureSWAPtotal]
Measure=SwapMemory
UpdateDivider=5
Total=1

[measurePageFileUsed]
Measure=Plugin
Plugin=PerfMon
UpdateDivider=5
PerfMonObject=Paging File
PerfMonCounter=% Usage
PerfMonInstance=_Total
PerfMonDifference=0

[measurePageFileTotal]
Measure=Calc
Formula=(measureSWAPtotal + 1880064) - measureRAMtotal

[measurePageFileUsedPerc]
Measure=Calc
Formula=(measurePageFileUsed * 4096) / measurePageFileTotal

;------------------------------------

[measurePageFaultsSec]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=Memory
PerfMonCounter=Pages/sec

[measurePageFaultsMaxHist]
Measure=Script
ScriptFile=#@#/FindMaxHistValue.lua
CurValue=[measurePageFaultsSec]
HistWidth=#HistogramWidth#


[measureOSver]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=Software\Microsoft\Windows NT\CurrentVersion
RegValue=CurrentVersion
UpdateDivider=-1
IfBelowValue=6.0
IfBelowAction=[!SetVariable cmdSYS "control.exe sysdm.cpl"][!SetVariable cmdPF "control.exe sysdm.cpl,,3"][!HideMeter "meterCPUfreq"][!DisableMeasure "measureCPUfreq"]
IfAboveValue=5.9
IfAboveAction=[!SetVariable cmdSYS "control.exe /name Microsoft.System"][!SetVariable cmdPF "SystemPropertiesPerformance.exe /pagefile"]
DynamicVariables=1

;------------------------------------
;------------------------------------


[MeterPageFaultsHistogram]
Meter=Histogram
MeasureName=measurePageFaultsSec
X=10
Y=([meterValueCPU0:Y] + (#CPUcores# * 10) + 15)
W=#HistogramWidth#
H=30
PrimaryColor=#colorGreen#
SolidColor=#colorGray#
AntiAlias=1
Autoscale=1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#
DynamicVariables=1

[MeterPageFaultsMaxHistText]
Meter=String
MeasureName=measurePageFaultsMaxHist
MeterStyle=styleRightTextSmall
X=160r
Y=0r
W=40
H=12
AutoScale=1
NumOfDecimals=0
Text=%1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterLabelPageFaultsCPU]
Meter=String
MeasureName=measurePageFaultsSec
MeterStyle=styleLeftTextSmall
X=10
Y=0r
W=140
H=14
Text=%1 #Faill#
Autoscale=2
NumOfDecimals=0
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

;-----------------------

[meterLabelRAM]
Meter=String
MeterStyle=styleLeftText
X=15
Y=33r
W=30
H=11
Text=MEM
FontColor=#colorCyan#
UpdateDivider=-1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterValueRAM]
Meter=String
MeterStyle=styleRightText
MeasureName=measureRAM
X=55r
Y=0r
W=30
H=14
Text=%1
Postfix=%
Percentual=1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterRAMtotal]
Meter=String
MeterStyle=styleRightText
MeasureName=measureRAMtotal
X=100r
Y=0r
W=60
H=14
Text=%1
Autoscale=1
NumOfDecimals=0
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterBarRAM]
Meter=Bar
MeterStyle=styleBarBlue
MeasureName=measureRAM
X=75
Y=5r
W=60
H=3
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

;-----------------------

[meterLabelSWAP]
Meter=String
MeterStyle=styleLeftText
X=15
Y=5r
W=30
H=11
Text=P/F
FontColor=#colorCyan#
UpdateDivider=-1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterValueSWAP]
Meter=String
MeterStyle=styleRightText
MeasureName=measurePageFileUsedPerc
X=55r
Y=0r
W=40
H=14
Text=%1
Postfix=%
Percentual=1
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterPageFileTotal]
Meter=String
MeterStyle=styleRightText
MeasureName=measurePageFileTotal
X=100r
Y=0r
W=60
H=14
Text=%1
Autoscale=1
NumOfDecimals=0
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#

[meterBarSWAP]
Meter=Bar
MeterStyle=styleBarYellow
MeasureName=measurePageFileUsedPerc
X=75
Y=5r
W=60
H=3
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#


;------------------------------
;------------------------------



[meterMemPagesMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([MeterPageFaultsHistogram:X] * #meterScaleCPU#)
Y=([MeterPageFaultsHistogram:Y] * #meterScaleCPU#)
W=([MeterPageFaultsHistogram:W] * #meterScaleCPU#)
H=([MeterPageFaultsHistogram:H] * #meterScaleCPU#)
LeftMouseUpAction=[perfmon.exe /res]
UpdateDivider=-1
DynamicVariables=1

[meterMEMsysMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterLabelRAM:X] * #meterScaleCPU#)
Y=([meterLabelRAM:Y] * #meterScaleCPU#)
W=([meterLabelRAM:W] * #meterScaleCPU#)
H=([meterLabelRAM:H] * #meterScaleCPU#)
MouseOverAction=[!SetOption meterLabelRAM FontColor #colorRed#][!SetOption meterLabelRAM Text "SYS"][!UpdateMeter "meterLabelRAM"][!Redraw]
MouseLeaveAction=[!SetOption meterLabelRAM FontColor #colorCyan#][!SetOption meterLabelRAM Text "MEM"][!UpdateMeter "meterLabelRAM"][!Redraw]
LeftMouseUpAction=[#cmdSYS#]
UpdateDivider=-1
DynamicVariables=1

[meterPFMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterLabelSWAP:X] * #meterScaleCPU#)
Y=([meterLabelSWAP:Y] * #meterScaleCPU#)
W=([meterLabelSWAP:W] * #meterScaleCPU#)
H=([meterLabelSWAP:H] * #meterScaleCPU#)
MouseOverAction=[!SetOption meterLabelSWAP FontColor #colorRed#][!UpdateMeter "meterLabelSWAP"][!Redraw]
MouseLeaveAction=[!SetOption meterLabelSWAP FontColor #colorCyan#][!UpdateMeter "meterLabelSWAP"][!Redraw]
LeftMouseUpAction=[#cmdPF#]
UpdateDivider=-1
DynamicVariables=1

[meterRAMavailMouseOver]
Meter=Image
Solidcolor=0,0,0,0
X=([meterValueRAM:X] * #meterScaleCPU#)
Y=([meterValueRAM:Y] * #meterScaleCPU#)
W=([meterValueRAM:W] * #meterScaleCPU#)
H=([meterValueRAM:H] * #meterScaleCPU#)
ToolTipText=[measureRAMavailScale]B Avail MEM
DynamicVariables=1

;-----------------------
