rm -rf "$HOME/Downloads/libft/"
cp -a "src/base/." "$HOME/Downloads/libft/"
cp -a "src/bonus/." "$HOME/Downloads/libft/"
cp "Makefile" "$HOME/Downloads/libft/"
cp "libft.h" "$HOME/Downloads/libft/"
cd "$HOME/Downloads/libft/" || exit
sed -i 's/..\/..\/libft.h/libft.h/g' *
sed -i 's/src\/base\///g' Makefile
sed -i 's/src\/bonus\///g' Makefile