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
    Start-Sleep -Seconds 10
}