
function Initialize()
  --
  -- this function is called when the script measure is initialized or reloaded
  --

  -- initialize array and vars for Histogram values just once when the skin is loaded
  tValues = {}
  PrevMax = 0
  PrevMaxIndex = 0
  HistMaxPrev = 0

  sHistWidth = SELF:GetOption('HistWidth', '1')
  nHistWidth = tonumber(sHistWidth)

  return
end

--
-----------------------
--

function Update()

  -- initialize local vars, the Histogram max scale is always a minimum of 2.
  local CurMax = 2
  local HistMax = 2
  local CurSize = 0

  -- get parameters from the Measure the script is called from.
  sInputValue = SELF:GetOption('CurValue', '0')

  -- validate input parameters
  nValue = tonumber(sInputValue)

  -- add new value to the list.
  table.insert(tValues, 1, nValue)
  CurSize = table.maxn(tValues)

  -- trim off oldest Value as it falls off the Histogram view.
  if CurSize > nHistWidth then
    table.remove(tValues, nHistWidth+1)
  end
  PrevMaxIndex = PrevMaxIndex + 1


  -- if new value is the new max, no need to scan all values for a max.
  if nValue >= PrevMax then

    PrevMax = nValue
    PrevMaxIndex = 1

  -- when the old max ages out of the buffer, need to scan for a new max.
  elseif PrevMaxIndex > nHistWidth then

    -- find the Max Value in the current Histogram view.
    CurSize = table.maxn(tValues)
    if CurSize >= 1 then
      i = 1
      while i <= CurSize do
        if CurMax < tValues[i] then
          CurMax = tValues[i]
          PrevMaxIndex = i
        end
        i = i + 1
      end
    end
    PrevMax = CurMax

  else

    -- if no reason to rescan for a new max, return the previous max.
    return HistMaxPrev

  end


  -- find the current Histogram Max Scale based on the new max value.
  while PrevMax > HistMax do
    HistMax = HistMax * 2
  end
  HistMaxPrev = HistMax

  -- return a numeric value and not a string, so the autoscaler will work.
  return HistMax

end

--
----------------------------------------------------------------------------------------------------
--
