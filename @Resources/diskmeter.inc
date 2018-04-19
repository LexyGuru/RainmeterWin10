[Rainmeter]
BackgroundMargins=0,0,0,0
Group=Disks|AllPerf
MouseOverAction=[!ShowMeter "meterOpenDiskConfigSkin"][!UpdateMeter "meterOpenDiskConfigSkin"][!Redraw]
MouseLeaveAction=[!HideMeter "meterOpenDiskConfigSkin"][!UpdateMeter "meterOpenDiskConfigSkin"][!Redraw]
OnRefreshAction=[!HideMeter "meterOpenDiskConfigSkin"][!UpdateMeter "meterOpenDiskConfigSkin"][!Redraw]

[Metadata]
Name=DiskMeter
Author=LexyGuru
Information=Shows disk usage and activity.
License=Creative Commons BY-NC-SA 3.0
Version=1.0.1

[Variables]
@IncludeGlobal=#@#globalsettings.inc
@IncludeHWiNFO=#@#HWiNFO.inc
HistogramWidth=80
disk1=#disk1#


;------------------------------
;------------------------------

[measureTotalDisk]
Measure=FreeDiskSpace
Drive=#disk1#
Total=1
UpdateDivider=10
IgnoreRemovable=0

[measureUsedDisk]
Measure=FreeDiskSpace
Drive=#disk1#
InvertMeasure=1
UpdateDivider=10
IgnoreRemovable=0

[measureAvailDisk]
Measure=FreeDiskSpace
Drive=#disk1#
UpdateDivider=10
IgnoreRemovable=0

[measureAvailDiskScale]
Measure=Script
ScriptFile=#@#/MinPrecision.lua
InputValue=[measureAvailDisk]
Precision=2
Factor=2

[MeasureDiskReadBytes]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=LogicalDisk
PerfMonCounter=Disk Read Bytes/sec
PerfMonInstance=#disk1#

[measureDiskReadBytesMaxHist]
Measure=Script
ScriptFile=#@#/FindMaxHistValue.lua
CurValue=[MeasureDiskReadBytes]
HistWidth=#HistogramWidth#

[MeasureDiskWriteBytes]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=LogicalDisk
PerfMonCounter=Disk Write Bytes/sec
PerfMonInstance=#disk1#

[measureDiskWriteBytesMaxHist]
Measure=Script
ScriptFile=#@#/FindMaxHistValue.lua
CurValue=[MeasureDiskWriteBytes]
HistWidth=#HistogramWidth#

;------------------------------
;------------------------------

[meterWidth]
Meter=Image
X=0
Y=0
W=(120 * #meterScaleDisk#)
H=0

[meterHeight]
Meter=Image
X=0
Y=0
W=0
H=(86 * #meterScaleDisk#)

;------------------

[meterOpenDiskConfigSkin]
Meter=String
X=(([meterWidth:W] / #meterScaleDisk#) - 15) 
Y=2
H=12
W=11
SolidColor=#colorGray#
FontColor=#colorWhiteDim#
StringStyle=Bold
FontSize=13
AntiAlias=1
Text=*
UpdateDivider=-1
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#


[meterDriveLabel]
Meter=String
X=0
Y=30
W=30
H=23
Fontsize=16
Fontcolor=#colorWhite#
Text=#disk1#
AntiAlias=1
UpdateDivider=-1
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#

[meterDriveSize]
Meter=String
MeasureName=measureTotalDisk
MeterStyle=styleLeftTextSmall
X=0
Y=18
W=30
H=12
Autoscale=2
NumOfDecimals=0
Text=%1
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#

[meterDriveUsed]
Meter=String
MeasureName=measureUsedDisk
MeterStyle=styleLeftTextSmall
X=0
Y=53
W=30
H=12
Percentual=1
NumOfDecimals=0
Text=%1
Postfix=%
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#

;------------------------------

[MeterReadBytesHistogram]
Meter=Histogram
MeasureName=MeasureDiskReadBytes
X=28
Y=10
W=#HistogramWidth#
H=30
PrimaryColor=#colorBlue#
SolidColor=#colorGray#
AntiAlias=1
AutoScale=1
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#


[MeterDiskReadBytesMaxHistText]
Meter=String
MeasureName=measureDiskReadBytesMaxHist
MeterStyle=styleRightTextSmall
X=80r
Y=0r
W=40
H=12
AutoScale=1
NumOfDecimals=0
Text=%1
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#


[MeterDiskReadBytes]
Meter=String
MeasureName=MeasureDiskReadBytes
MeterStyle=styleLeftTextSmall
X=28
Y=10
W=80
H=12
AutoScale=1
NumOfDecimals=0
Prefix="R "
Text=%1
Postfix=B
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#

;-----------

[meterBarDiskUsed]
Meter=Bar
MeasureName=measureUsedDisk
MeterStyle=styleBarYellow
X=28
Y=31r
W=80
H=4
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#

;-----------

[MeterWriteBytesHistogram]
Meter=Histogram
MeasureName=MeasureDiskWriteBytes
X=0r
Y=5r
W=#HistogramWidth#
H=30
PrimaryColor=#colorRed#
SolidColor=#colorGray#
AntiAlias=1
AutoScale=1
Flip=1
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#

[MeterDiskWriteBytes]
Meter=String
MeasureName=MeasureDiskWriteBytes
MeterStyle=styleLeftTextSmall
X=0r
Y=17r
W=80
H=12
AutoScale=1
NumOfDecimals=0
Prefix="W "
Text=%1
Postfix=B
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#

[MeterDiskWriteBytesMaxHistText]
Meter=String
MeasureName=measureDiskWriteBytesMaxHist
MeterStyle=styleRightTextSmall
X=80r
Y=0r
W=40
H=12
AutoScale=1
NumOfDecimals=0
Text=%1
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#


;------------------------------
;--- had to create manual scalable clickable areas, as the TransformationMatrix does not work well with mouse clicks ---

[meterDiskReadMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([MeterReadBytesHistogram:X] * #meterScaleDisk#)
Y=([MeterReadBytesHistogram:Y] * #meterScaleDisk#)
W=([MeterReadBytesHistogram:W] * #meterScaleDisk#)
H=([MeterReadBytesHistogram:H] * #meterScaleDisk#)
LeftMouseUpAction=[perfmon.exe /res]
UpdateDivider=-1

[meterDiskWriteMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([MeterWriteBytesHistogram:X] * #meterScaleDisk#)
Y=([MeterWriteBytesHistogram:Y] * #meterScaleDisk#)
W=([MeterWriteBytesHistogram:W] * #meterScaleDisk#)
H=([MeterWriteBytesHistogram:H] * #meterScaleDisk#)
LeftMouseUpAction=[perfmon.exe /res]
UpdateDivider=-1

[meterDriveLabelMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterDriveLabel:X] * #meterScaleDisk#)
Y=([meterDriveLabel:Y] * #meterScaleDisk#)
W=([meterDriveLabel:W] * #meterScaleDisk#)
H=([meterDriveLabel:H] * #meterScaleDisk#)
LeftMouseUpAction=["#disk1#\"]
UpdateDivider=-1

[meterDriveSizeMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterDriveSize:X] * #meterScaleDisk#)
Y=([meterDriveSize:Y] * #meterScaleDisk#)
W=([meterDriveSize:W] * #meterScaleDisk#)
H=([meterDriveSize:H] * #meterScaleDisk#)
LeftMouseUpAction=[systempropertiesprotection.exe]
UpdateDivider=-1

[meterDriveUsedMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterDriveUsed:X] * #meterScaleDisk#)
Y=([meterDriveUsed:Y] * #meterScaleDisk#)
W=([meterDriveUsed:W] * #meterScaleDisk#)
H=([meterDriveUsed:H] * #meterScaleDisk#)
LeftMouseUpAction=[cleanmgr.exe /d#disk1#]
UpdateDivider=-1

[meterAvailDiskMouseOver]
Meter=Image
Solidcolor=0,0,0,0
X=([meterDriveUsed:X] * #meterScaleDisk#)
Y=([meterDriveUsed:Y] * #meterScaleDisk#)
W=([meterDriveUsed:W] * #meterScaleDisk#)
H=([meterDriveUsed:H] * #meterScaleDisk#)
ToolTipText=[measureAvailDiskScale]B Avail
DynamicVariables=1

[meterOpenDiskConfigMouseClick]
Meter=Image
Solidcolor=0,0,0,0
X=([meterOpenDiskConfigSkin:X] * #meterScaleDisk#)
Y=([meterOpenDiskConfigSkin:Y] * #meterScaleDisk#)
W=([meterOpenDiskConfigSkin:W] * #meterScaleDisk#)
H=([meterOpenDiskConfigSkin:H] * #meterScaleDisk#)
ToolTipText=Settings
LeftMouseUpAction=[!ToggleConfig "#DiskConfigSkinLoc#" "diskconfig.ini"]
UpdateDivider=-1

;------------------------------

[HWiNFOMBDiskTemp]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#HWiNFO-SMART-Temp-SensorId#
HWiNFOSensorInstance=#HWiNFO-SMART-Temp-SensorInstance#
HWiNFOEntryId=#HWiNFO-SMART-Temp-Entry#
HWiNFOType=CurrentValue
DynamicVariables=1
Disabled=#DriveTempOnOff#

[HWiNFOMBDiskTempUnits]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#HWiNFO-SMART-Temp-SensorId#
HWiNFOSensorInstance=#HWiNFO-SMART-Temp-SensorInstance#
HWiNFOEntryId=#HWiNFO-SMART-Temp-Entry#
HWiNFOType=Units
DynamicVariables=1
Disabled=#DriveTempOnOff#


[meterDriveTemp]
Meter=String
MeasureName=HWiNFOMBDiskTemp
MeasureName2=HWiNFOMBDiskTempUnits
MeterStyle=styleLeftTextSmall
X=0
Y=65
W=30
H=12
NumOfDecimals=0
Text=%1%2
TransformationMatrix=#meterScaleDisk#;0;0;#meterScaleDisk#;#meterScaleDisk#;#meterScaleDisk#
Hidden=#DriveTempOnOff#

;------------------------------
