main(w,h,i){scanf("%d%d",&h,&w);for(i=++w*h;i--;)putchar(-~i%w>2&i>w&i<w*h-w?32:i%w?42:10);}
