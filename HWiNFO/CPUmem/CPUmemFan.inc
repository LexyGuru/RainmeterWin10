
[measureCPU0MBFanRpm]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#HWiNFO-CPU0-MB-SensorId#
HWiNFOSensorInstance=#HWiNFO-CPU0-MB-SensorInstance#
HWiNFOEntryId=#HWiNFO-CPU0-MB-Fan-Rpm#
HWiNFOType=CurrentValue
Disabled=#CPU0FanOnOffSelect#

[meterCPU0MBFanRpm]
Meter=String
MeasureName=measureCPU0MBFanRpm
MeterStyle=styleRightTextSmall
;;X=[MeterCPUHistogram:X]
;;Y=([MeterCPUHistogram:Y] + [MeterCPUHistogram:H] - [meterCPU0MBFanRpm:H])
X=([MeterCPUHistogram:X] + 103)
Y=[MeterCPUHistogram:Y]
W=45
H=12
Text=%1 rpm
TransformationMatrix=#meterScaleCPU#;0;0;#meterScaleCPU#;#meterScaleCPU#;#meterScaleCPU#
DynamicVariables=1
Hidden=#CPU0FanOnOffSelect#
;SolidColor=0,0,0,100