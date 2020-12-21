cat /etc/passwd | grep -v '^#' | awk 'NR==1 || (NR>1 && NR%2==0)' | grep -oE '^[^:]+' | rev | sort -fr | awk 'NR>=a+1 && NR<=b+1' a=$FT_LINE1 b=$FT_LINE2  | tr  '\n' ',' | sed 's/,$/./' | tr -d '\n'

