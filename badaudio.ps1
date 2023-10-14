function getDate {
    Get-Date -Format "dddd MM/dd/yyyy HH:mm K"
    $year = Get-Date -Format yyyy;
    $month = Get-Date -Format MM;
    $month = [int]$month.ToString()
    $day = Get-Date -Format dd;
    $day = [int]$day.ToString()
    return $year + "-" + $month + "-" + $day
}

function getTime {
    Get-Date -Format "dddd MM/dd/yyyy HH:mm K"
    $hour = Get-Date -Format hh;
    $hour = [int]$hour.ToString();
    $min = Get-Date -Format mm;
    $min = [int]$min.ToString();
    $secf = Get-Date -Format ss;
    $secf = [int]$secf.ToString();
    return $hour.ToString() + "." + $min + "." + $secf;
}

function Get-BadAudio {
    get-process python | select-object Id,NPM | ForEach-Object {
        if ($_.NPM -gt 100000) {
            Write-Output "Process NPM: ", $_.NPM;
            $dateStr = getDate;
            $timeStr = getTime;
            $path = ".\logs\errors\" + $dateStr + "\\austin_trace_" + $timeStr + ".log";
            austin -p $_.Id --exposure=5 -o $path;
            taskkill /f /im $_.Id;
        }
    }
}

while ($true) {
    Get-BadAudio;
    Start-Sleep -Seconds 10;
}