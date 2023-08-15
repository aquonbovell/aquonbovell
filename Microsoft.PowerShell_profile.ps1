Import-Module -Name Terminal-Icons

Set-PSReadLineOption -PredictionSource History
Set-PSReadLineOption -PredictionViewStyle ListView
Set-PSReadLineOption -EditMode Windows 

Set-Alias -Name ls -Value lsd
Set-Alias -Name ll -Value longList
function longList {
	lsd -alt
}
# oh-my-posh init pwsh --config 'C:/Users/aquon/microverse-power.omp.json' | Invoke-Expression
$ENV:STARSHIP_CONFIG = "$HOME\.config\starship.toml"
Invoke-Expression (&starship init powershell)