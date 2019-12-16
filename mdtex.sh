#!/bin/sh

echo "マークダウンで書いたものをLaTeXに変換するツール"
read -p "please input your file: " file

mdfile="${file}.md"
texfile="${file}.tex"

echo "${mdfile}を${texfile}に変換します"

pandoc $mdfile -o $texfile
ruby tex.rb $texfile

platex master.tex

dvipdfmx master.dvi
