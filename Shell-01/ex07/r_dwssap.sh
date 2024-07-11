cat /etc/passwd | sed '/^#/d' | awk 'NR % 2 == 0 {print $0}' | awk -F ":" '{  print $1 }' | rev | sort -fnr  | tr '\n' ' '  | sed 's+ +, +g' | sed 's+, $+.+g' | tr -d '\n'
