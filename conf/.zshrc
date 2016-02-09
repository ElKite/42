PATH=$HOME/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin
HISTFILE=~/.zshrc_history
SAVEHIST=5000
HISTSIZE=5000

setopt inc_append_history
setopt share_history

if [[ -f ~/.myzshrc ]]; then
  source ~/.myzshrc
fi

USER=`/usr/bin/whoami`
export USER
GROUP=`/usr/bin/id -gn $user`
export GROUP
MAIL="$USER@student.42.fr"

export MAIL

export MANPAGER=MOST

alias ionic='/./nfs/zfs-student-3/users/vtarreau/node_modules/ionic/bin/ionic'
alias cordova='/./nfs/zfs-student-3/users/vtarreau/node_modules/cordova/bin/cordova'
alias la ='ls -la'