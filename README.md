Required:
Wireshark &
Airport Utility


add to path run :
cp JPWS /usr/local/bin/JPWS

install:
Homebrew:

/bin/bash -c "$(curl -fsSL 
https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"

Airport:

sudo ln -s /System/Library/PrivateFrameworks/Apple80211.framework/\ 
Versions/Current/Resources/airport /usr/sbin/airport

Wireshark:
brew install wireshark
