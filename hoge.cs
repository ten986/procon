using System;
namespace inonoa{
    class Ino{
        static void Main(){
            string[] input = Console.ReadLine().Split();
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            int c = int.Parse(input[2]);
            int x = int.Parse(input[3]);
            int y = int.Parse(input[4]);

            int ans = 0;

            if(a>c){
                if(b>c){
                    if(x>y){
                        ans += y*2*c;
                        x -= y;
                        y = 0;
                        ans += Math.Min(2*x*c,x*a);
                        Console.WriteLine(ans);
                        return;
                    }else{
                        ans += x*2*c;
                        y -= x;
                        x = 0;
                        ans += Math.Min(2*y*c,x*b);
                        Console.WriteLine(ans);
                        return;
                    }
                }else if((a+b)/2.0f>=c){
                    if(x>y){
                        ans += y*2*c;
                        x -= y;
                        y = 0;
                        if(a>2*c){
                            ans += x*2*c;
                            Console.WriteLine(ans);
                            return;
                        }else{
                            ans += x*a;
                            Console.WriteLine(ans);
                            return;
                        }
                    }else{
                        ans += x*2*c;
                        y -= x;
                        x = 0;
                        if(b>2*c){
                            ans += x*2*c;
                            Console.WriteLine(ans);
                            return;
                        }else{
                            ans += y*b;
                            Console.WriteLine(ans);
                            return;
                        }
                    }
                }else{
                    ans += a*x + b*y;
                    Console.WriteLine(ans);
                    return;
                }
            }else{
                if(b>c){
                    if((a+b)/2.0f>=c){
                        if(y>x){
                            ans += x*2*c;
                            y -= x;
                            x = 0;
                            if(b>2*c){
                                ans += y*2*c;
                                Console.WriteLine(ans);
                                return;
                            }else{
                                ans += x*a;
                                Console.WriteLine(ans);
                                return;
                            }
                        }else{
                            ans += x*2*c;
                            y -= x;
                            x = 0;
                            if(b>2*c){
                                ans += x*2*c;
                                Console.WriteLine(ans);
                                return;
                            }else{
                                ans += x*a;
                                Console.WriteLine(ans);
                                return;
                            }
                        }
                    }else{
                        ans += a*x + b*y;
                        Console.WriteLine(ans);
                        return;
                    }
                }else{
                    ans += a*x + b*y;
                    Console.WriteLine(ans);
                    return;
                }
            }
        }
    }
}
