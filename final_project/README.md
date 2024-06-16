# Final Project README
###### author 張貓芋圓 資工116張祐豪 圖傳115宋品頤 資工116陳育渝

**github repository**
https://github.com/cyucccx/CP2-final-project

```
./final_project
├── Makefile
├── assets/
|   ├── home/
|   |   ├── load.png
|   |   ├── start.png
|   |   └── menu.png
|   ├── scene/
|   |   ├── backpack.png
|   |   ├── background.png
|   |   ├── character1.png
|   |   |   ...
|   |   ├── name_blank.png
|   |   ├── select.png
|   ├── music/
|   |   ├── bgm1.mp3
|   |   |   ...
|   |   ├── SE_select.mp3
|   └── backpack/
|       ├── item1.png
|       └──  ...
├── game/
|   ├── SDL_function.c
|   ├── include.h
|   ├── main.c
|   ├── script.toml
|   └── simfang.ttf
└── README
```
## 基本功能
支援場景、人物、物品、人物頭像、人物立繪、物品圖標、對話選項、支線劇情
## 額外功能
場景動畫、心情變換、音效播放、遊戲存檔
## 遊玩方式
1. 在終端機執行`make`
2. 在`final_project`目錄下執行 `./bin/interactive_novel_engine`
## script 編寫規則
```
.
├── project_name
├── home
├── select_character
└── event
    ├── backpack
    └── dialogue
        └── reply
```
### name
```toml!
project_name = "Final Project"
```
`project_name`是介面會出現的視窗名稱

### home
```toml
[home]
bgm = "../assets/music/bgm1.mp3"
background = "../assets/home/menu.png"
max_character = 15 #(1~15)
```
`[home]`是設定主畫面的小標
`bgm`是遊戲中播放的背景音樂
`background`是主畫面的背景
`max_character`先設定登場人物上限

### select_character
```toml
[select_character]
name1 = "Jacob"
avatar_choose1 = "../assets/scene/jacob.png"
avatar1 = "../assets/scene/head_jacob.png"
name2 = "Howard"
avatar_choose2 = "../assets/scene/howard.png"
avatar2 = "../assets/scene/head_howard.png"
name3 = "Sky"
avatar_choose3 = "../assets/scene/sky.png"
avatar3 = "../assets/scene/head_sky.png"
name4 = "Ryan"
avatar_choose4 = "../assets/scene/ryan.png"
avatar4 = "../assets/scene/head_ryan.png"
name5 = "Takala"
avatar_choose5 = "../assets/scene/takala.png"
avatar5 = "../assets/scene/head_takala.png"
```
`[select_character]`是選擇主角的小標

`name`是主角的名字

`avatar_choose`是主角選擇介面中主角的圖片

`avatar`是劇情對話中主角的頭像

### event
```toml
[chi_1_start] #中間不能空格
background = "../assets/scene/road.png"
character_number = 3 #(0~6)
name = "博玟"
photo = "../assets/scene/chi.png"
avatar = "../assets/scene/head_chi.png"
name = "me"
photo = "null"
avatar = "me_avatar"
name = "旁白"
photo = "null"
avatar = "null"
```
每個event 後面不一定要接子集，如果沒有加backpack 就代表背包內無物品

`character_number`是出現在畫面的角色人數，最多不超過max_character的人數，最少0人

有n個character後面會接n個name, photo, favor

`name`是character的名字

`photo`是那個character的立繪

**如果是主角或旁白的對話，沒有立繪，直接在photo後面放`"null"`即可**

`avatar`是人物頭像，跟photo一樣，如果沒圖片放null即可
#### backpack
```toml
[[jiang_3_start.backpack]] 
items_number = 3
name = "Razer Blade 16"
photo = "../assets/backpack/laptop.png"
description = "全球第一台配備OLED 240Hz 16吋顯示器的電競筆電，讓你體驗驚人的鮮明視覺與色彩深度"
name = "中晢訂正的筆記"
photo = "../assets/backpack/note.png"
description = "細心的訂正好了我沒搞清楚的觀念和Writing Style，雖然讓人壓力有點大但改得真好"
name = "電影票根"
photo = "../assets/backpack/ticket.png"
description = "《排球少年！！垃圾場的決戰》4DX電影票，描述一群少年在垃圾場將球排整齊的熱血故事"
```
如果沒出現backpack的子集，就預設背包內無道具

如果有backpack需放在子集的第一個位置

`items_number`是在當下event 背包內的物品數量，最多3項

有幾項物品，後面會接幾個name, photo, discription

`name`就是道具名稱

`photo`是道具圖片

`description`是道具簡介，裡面放string介紹道具功能
#### dialogue
```toml
[[wang_3_good.dialogue]]
string_number = 2 #(0~100)
speaker = "虹倫"
text = "哈 哈 哈，好喔"
speaker = "旁白"
text = "雖然帶著挖苦的語氣，不過虹倫的微笑好像變得更柔和了一點"
next = "[wang_3_end]"
```
**不一定每個event都會有對話**

`string_number`代表總共會出現的字串數量

之後有幾條string 就會有幾個speaker, text

`speaker`就是當下在說話的character

`text`就是應該要出現的相對應string

`next`就是在沒有reply的時候要直接結束這個event 要跳到下個event，略過中間可能會出現的子事件

dialogue的子集需放在子集的第二個位置

如果有reply 或是沒有要跳轉的事件就在next 後面放`"null"`

**注意 如果dialogue.next不是null，後面就不能放reply**
#### reply
```toml
[[jiang_3_start.reply]]
object = "中晢"
option1 = "你真的超噁"
change_favor1 = -5 #(-5~+5)
next1 = "[jiang_3_bad]"
option2 = "哈哈該不會是你剛遇到虹倫她跟你說的吧"
change_favor2 = +5
next2 = "[jiang_3_normal]"
option3 = "下次不要用跟蹤的，直接約我就好了啊" 
change_favor3 = +5
next3 = "[jiang_3_good]"
```
dialogue 的子集，如果沒有dialogue 就不會有reply

如果有reply需放在子集的第三個位置

`object`是改變好感度的對象

`option`是回覆的選項

`change_favor`就是選擇這個`option`會改變`favor`的數值

`next`後面接的是`[event]`會直接switch 到下一個event

#### final event reply
在最後兩幕，因為會需要用到favor去比較結局是好是壞，所以另外寫了一個不同的reply格式，所以規定結局前一個事件一定是`[final_event]`
```toml
[[final_event.reply]]
object1 = "博玟"
option1 = "博玟"
change_favor1 = 0
favor_threshold1 = 10
good_next1 = "[goodend_chi]"
bad_next1 = "[badend_chi]"
object2 = "虹倫"
option2 = "虹倫"
change_favor2 = 0
favor_threshold2 = 15
good_next2 = "[goodend_wang]"
bad_next2 = "[badend_wang]"
object3 = "中晢"
option3 = "中晢" 
change_favor3 = 0
favor_threshold3 = 1
good_next3 = "[goodend_jiang]"
bad_next3 = "[badend_jiang]"
```
和前面不一樣的是這邊每個選項都有object和favor_threshold，如果選擇的選項object的好感度不足，就會跳去壞結局，所以這邊會有6種結局可以寫（結局的事件不能有reply）

## 可透過劇本檔改變的媒體素材

要置換的素材必須放在與範例劇本檔中相同的路徑下

若要自訂圖片，建議使用png檔案格式，否則畫面效果可能無法完整顯示或出現錯誤

### 可更改之圖片(後為尺寸限制):

#### 遊戲主畫面
主畫面背景（`[home]`下的background）：800 * 600
#### 主角選擇介面
主角圖片（`[select_character]`下各個avatar_choose）：98 * 100
#### 遊戲劇情介面
* 背景圖（各個event下的background）：800 * 600
* 角色立繪（各個event下的photo）：800 * 600
* 角色頭像（各個event下的avatar）：98 * 115
#### 背包介面
道具（各個backpack下的photo）：65 * 65
### 可更改之音樂：

主畫面BGM（`[home]`下的bgm）：建議為MP3檔

### 可更改之文字(後為長度限制):
* 主角姓名( `[select_character]`中各個name )：7個半形字符
* 說話者姓名( dialog下的各個speaker )：16個半形字符
* 劇情對話( dialog下的各個text )：160個半形字符
* 選項文字( reply下的各個option )：52個半形字符
* 道具名稱( backpack下的各個name )：18個半形字符
* 道具敘述( backpack下的各個description )：145個半形字符


## 素材來源

* UI素材：[空想曲線](https://kopacurve.blog.fc2.com/blog-entry-394.html) 
* 背景素材：[きまぐれアフター背景素材置き場](https://gakaisozai.seesaa.net/article/202102article_1.html)
* 音樂、音效：[魔王魂](https://maou.audio/rule/)
