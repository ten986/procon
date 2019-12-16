f_name = ARGV[0].to_s
f=File.open(f_name,"r")
buffer = f.read();
buffer.gsub!("\\tightlist" , "\n");
f=File.open(f_name,"w")
f.write(buffer)
f.close()
puts "正常に置換が終了しました"
