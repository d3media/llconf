(done (and vim bash))

(vim (and (installed vim) configured_vim))

(bash (and (installed bash) configured_bash))

(configured_bash
 (sync_to ("$HOME/.bashrc" (template "bashrc")))
)

(configured_vim
 (sync_to ("$HOME/.vimrc (template "vimrc")))
)

(installed
 (or
  (and (debian) (apt_installed (arg 0)))
  (and (fedora) (yum_installed (arg 0)))
 )
)


(git 
 (or
  (and (exec "git fetch --all") (exec "git status"))
  (exec (add "git clone" (arg 0)))
 )
)
