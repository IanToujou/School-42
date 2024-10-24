cd "$HOME/Downloads/libft" || exit
for f in ft_*; do mv "$f" "${f/_bonus/}";done
sed -i 's/_bonus//g' Makefile
cd ..
rm -rf "libft-unit-test"
git clone https://github.com/alelievr/libft-unit-test
cd libft-unit-test || exit
make f