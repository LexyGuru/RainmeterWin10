function Initialize()
  --
  -- this function is called when the script measure is initialized or reloaded
  --

  -- the -1 will force the update to process the first value.
  PrevValue = -1
  asSuffix = { " ", " k", " M", " G", " T", " P", " E", " Z", " Y" }
  PrevText = "0.0 "
  nDigitsAfterDecimal = 0
  nDigitsBeforeDecimal = 0
  sPattern = ""
  sText = ""
  nDivisor = 1024.0


  sPrecision = SELF:GetOption('Precision', '2')
  sFactor = SELF:GetOption('Factor', '1')


  -- validate Scale/Precision
  nPrecision = math.floor(tonumber(sPrecision)) or 3
  if nPrecision > 0 then
    -- OK
  else
    -- invalid input
    nPrecision = 3
  end

  -- validate Factor and set divisor if needed
  if sFactor == "1" or sFactor == "1k" then
    -- OK
  elseif sFactor == "2" or sFactor == "2k" then
    nDivisor = 1000.0
  else
    sFactor = "0"
    nDivisor = 1.0
  end


  return
end

--
-----------------------
--

function Update()

  nDivCount = 1

  sInputValue = SELF:GetOption('InputValue', '0')
  nInputValue = tonumber(sInputValue)

  -- if the Value has not changed, just return the previous Text.
  if nInputValue == PrevValue then
    return PrevText
  end
  PrevValue = nInputValue

  -- if minimum value is K, divide value by divisor.
  if sFactor == "1k" or sFactor == "2k" then
    nInputValue = nInputValue / nDivisor
    nDivCount = nDivCount + 1
  end

  while (math.abs(nInputValue) > nDivisor and nDivCount < 9 and nDivisor > 1.0) do
    nInputValue = nInputValue / nDivisor
    nDivCount = nDivCount + 1
  end

  nDigitsBeforeDecimal = math.max(1, math.floor(math.log10(math.abs(nInputValue))) + 1)
  nDigitsAfterDecimal = math.max(0, nPrecision - nDigitsBeforeDecimal)

  -- get formatting directive.
  sPattern = "%." .. nDigitsAfterDecimal .. "f"

  -- format the number.
  sText = string.format(sPattern, nInputValue)
  PrevText = sText  .. asSuffix[nDivCount]

  return PrevText

end

--
----------------------------------------------------------------------------------------------------
--
