while ($true) {
    Get-WmiObject Win32_process -filter 'name = "vbanStream_clock.exe"' | foreach-object { 
        if ($_.priority -ne 13) {
            $_.SetPriority(256)
        }
    }
    Get-WmiObject Win32_process -filter 'name = "vbanStream_fireplace.exe"' | foreach-object { 
        if ($_.priority -ne 13) {
            $_.SetPriority(256)
        }
    }
    Get-WmiObject Win32_process -filter 'name = "vbanStream_window.exe"' | foreach-object { 
        if ($_.priority -ne 13) {
            $_.SetPriority(256)
        }
    }
    Get-WmiObject Win32_process -filter 'name = "vbanStream_outside.exe"' | foreach-object { 
        if ($_.priority -ne 13) {
            $_.SetPriority(256)
        }
    }
    Get-WmiObject Win32_process -filter 'name = "vbanStream_porch.exe"' | foreach-object { 
        if ($_.priority -ne 13) {
            $_.SetPriority(256)
        }
    }
    Get-WmiObject Win32_process -filter 'name = "vbanStream_generic.exe"' | foreach-object { 
        if ($_.priority -ne 13) {
            $_.SetPriority(256)
        }
    }
    Get-WmiObject Win32_process -filter 'name = "vbanStream_light.exe"' | foreach-object { 
        if ($_.priority -ne 13) {
            $_.SetPriority(256)
        }
    }

    $numberOfCores = (Get-CimInstance Win32_Processor).NumberOfCores
    $affinity = [Math]::Pow(2, $numberOfCores) - 1

    # manual $affinity = 63
    Get-Process "vbanStream_clock" | ForEach-Object { $_.ProcessorAffinity = $affinity; };
    Get-Process "vbanStream_fireplace" | ForEach-Object { $_.ProcessorAffinity = $affinity; };
    Get-Process "vbanStream_window" | ForEach-Object { $_.ProcessorAffinity = $affinity; };
    Get-Process "vbanStream_outside" | ForEach-Object { $_.ProcessorAffinity = $affinity; };
    Get-Process "vbanStream_generic" | ForEach-Object { $_.ProcessorAffinity = $affinity; };
    Get-Process "vbanStream_porch" | ForEach-Object { $_.ProcessorAffinity = $affinity; };
    Get-Process "vbanStream_light" | ForEach-Object { $_.ProcessorAffinity = $affinity; };
    Get-Process "ambience" | ForEach-Object { $_.ProcessorAffinity = $affinity; };

    Start-Sleep -Seconds 3
}