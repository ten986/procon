// ライブラリを読み込み（よくわからなかったらとりあえずそのままにしておいてください）
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

// ゲームシステム用変数（よくわからなかったらとりあえずそのままにしておいてください）
// キーボード入力管理用のKeyboardManager
KeyboardManager keyman;
// フォント（環境によって違ったらヤバそうなので一応スケッチに付属させたVLゴシックを使うことにしている）
PFont font;

// Minimライブラリ用の変数
Minim minim;
// ゲームシステム用変数ここまで


// 以下にグローバル変数を宣言します
Object player;

int jump;

ArrayList<Object> enemies;
ArrayList<Object> police;
ArrayList<Object> police2;
ArrayList<Object> police3;
ArrayList<Object> police4;

int frame;
int pframe;
int pframe2;
int pframe3;
int pframe4;
int bound;

boolean gameover;
// グローバル変数ここまで


// スケッチ実行時に最初に１度だけ実行されます
void setup() {
  // ゲームの初期化
  // ゲームシステムの初期化（よくわからなかったらとりあえずそのままにしておいてください）
  print("文字列描画を初期化中......");
  // KeyboardManagerのインスタンスを作成
  keyman = new KeyboardManager();
  // フォントを読み込む
  font = createFont("fonts/VL-PGothic-Regular.ttf", 24);
  if(font == null) {
    // ここで読み込めていない場合はWindowsと同じで'\'で区切るのかもしれない
    font = createFont("fonts\\VL-PGothic-Regular.ttf", 24);
  }
  textFont(font);
  // 文字描画位置を設定する（座標が左上）
  textAlign(LEFT, TOP);
  println("\t[ OK ]");
  
  print("ビデオを初期化中......");
  // 画面サイズを設定（左から順に幅と高さ）
  size(800, 600);
  // フレームレート（単位はフレーム毎秒）
  // １秒間にここに指定した回数だけdraw()が呼ばれる
  frameRate(30);
  println("\t[ OK ]");
  
  print("サウンドシステムを初期化中......");
  // 音声ライブラリ初期化
  minim = new Minim(this);
  println("\t[ OK ]");
  
  println("完了.");
  // ゲームシステムの初期化ここまで
  
  
  // 以下に追加の初期化処理を書きます
  player=new Object();
  player.image=loadImage("dorobou_hokkamuri.png");
  player.x=100;
  player.y=450;
  player.r=50;
  jump=0;
  
  enemies=new ArrayList<Object>();
  police=new ArrayList<Object>();
  police2=new ArrayList<Object>();
  police3=new ArrayList<Object>();
  police4=new ArrayList<Object>();
  
  frame=60;
  pframe=100;
  pframe2=200;
  pframe3=300;
  pframe4=400;
  
  gameover=false;
  
  bound=0;
  // 初期化処理ここまで
}

// ゲームメインループ
void draw(){
  // キー入力情報の更新
  keyman.updateKeys();
  // 画面の消去（背景色をここで指定する）
  background(255, 255, 255);
  
  // 以下にゲームの処理を書きます
  if(gameover){
    PImage image=loadImage("taiho.png");
    image(image,0,0);
  }else{
  
   if(bound<=0){ 
  if(keyman.getSpecialKey(LEFT)){
    player.x-=10;
  }
  if(keyman.getSpecialKey(RIGHT)){
    player.x+=10;
  }
  if(keyman.getKey("z")&&jump<=0){
    jump=39;
  }
  
  if(jump>=0){
    player.y=(jump-20)*(jump-20)+50;
    jump--;
  }
  
  rImage(player.image,player.x,player.y,100,100,0);
 }else{
   bound--;
   player.x+=10;
  rImage(player.image,player.x,player.y,100,100,45);
 }
 
 if(player.x<0){
   player.x=0;
 }
 
 if(player.x>800){
   player.x=800;
 }
  
  frame--;
  
  if(frame<=0){
      Object enemy=new Object();
  enemy.x=-100;
  enemy.y=450;
  enemy.r=50;
  enemy.image=loadImage("kusa_simple3.png");
  
  enemies.add(enemy);
  
  frame=(int)random(100,200);
  }
  
  for(Object enemy:enemies){
    enemy.x+=7;
  rImage(enemy.image, enemy.x, enemy.y, 100,100,0);
    if(isHit(enemy,player)){
      bound=15;
      player.x=enemy.x+100;
    }
  }
    
   pframe--;
  
  if(pframe<=0){
      Object enemy=new Object();
  enemy.x=900;
  enemy.y=450;
  enemy.r=50;
  enemy.image=loadImage("police_man_kenju_gun.png");
  
  police.add(enemy);
  
  pframe=(int)random(100,200);
  }
  
  for(Object enemy:police){
    enemy.x-=10;
  rImage(enemy.image, enemy.x, enemy.y, 100,100,0);
    if(isHit(enemy,player)){
      gameover=true;
    } 
  }
  
  pframe2--;
  
  if(pframe2<=0){
      Object enemy=new Object();
  enemy.x=900;
  enemy.y=150;
  enemy.r=50;
  enemy.image=loadImage("helicopter_keisatsu_heli.png");
  
  police2.add(enemy);
  
  pframe2=(int)random(200,400);
  }
  
  for(Object enemy:police2){
    enemy.x-=6;
  rImage(enemy.image, enemy.x, enemy.y, 100,100,0);
    if(isHit(enemy,player)){
      gameover=true;
    } 
  }
  
  pframe3--;
  
  if(pframe3<=0){
      Object enemy=new Object();
  enemy.x=900;
  enemy.y=450;
  enemy.r=50;
  enemy.image=loadImage("tsuuhou_110_police.png");
  
  police3.add(enemy);
  
  pframe3=(int)random(300,600);
  }
  
  for(Object enemy:police3){
    enemy.x-=20;
  rImage(enemy.image, enemy.x, enemy.y, 100,100,0);
    if(isHit(enemy,player)){
      gameover=true;
    } 
  }
  
  
    pframe4--;
  
  if(pframe4<=0){
      Object enemy=new Object();
  enemy.x=900;
  enemy.y=450;
  enemy.r=50;
  enemy.image=loadImage("war_sensya_man.png");
  
  police4.add(enemy);
  
  pframe4=(int)random(1000,2000);
  }
  
  for(Object enemy:police4){
    enemy.x-=1;
  rImage(enemy.image, enemy.x, enemy.y, 100,100,0);
    if(isHit(enemy,player)){
      gameover=true;
    } 
  }
  }
  // ゲームの処理ここまで
}

boolean isHit(Object a,Object b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))<(a.r+b.r);
}

class Object{
  float x;
  float y;
  float r;
  PImage image;
}

// 何かキーが押されたときに行う処理を書きます
void keyPressed() {
  // 押されたキーを確認する（KeyboardManager keymanを動作させるために必要）
  keyman.keyPressedHook();
}
// 何かキーが離されたときに行う処理を書きます
void keyReleased() {
  // 離されたキーを確認する（KeyboardManager keymanを動作させるために必要）
  keyman.keyReleasedHook();
}
