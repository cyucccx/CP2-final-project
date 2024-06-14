```
.
├── name and author
├── home
└── event
    ├── backpack
    └── dialogue
        └── reply
```

```
./assets
├── home/
|   ├── background.png
|   ├── button.png
|   ├── backpack_background.png
├── scene/
|   ├── background.png
|   ├── backpack_icon.png
|   ├── character1.png
|   |   ...
|   ├── dialogue_box.png
|   └── option_box.png
└── backpack/
    └── item1.png
        ...
```
## name and author
```toml
project_name = "Final Project"
author = "張貓芋圓"
```
`project_name`是介面會出現的視窗名稱

`author`是劇本編寫人

## home
```toml
[home]
background = "assets/home/background.png"
button = "assets/home/button.png"
backpack_background = "assets/home/backpack_background.png"
max_character = 5 #(1~15)
```
`[home]`是設定主畫面的小標

`background`是主畫面的背景

`button`是選擇遊戲開始的按鍵

`backpack_ground`在這裡先設定背包畫面的背景

`max_character`先設定登場人物上限

## event
```toml
[professor.discussing] #event #中間不能空格
background = "assets/scene/background.png"
backpack_icon = "assets/scene/backpack_icon.png"
character_number = 3 #(0~6)
name = "L紀"
photo = "assets/scene/L紀.png"
avatar = "assets/scene/L紀.png"
name = "TCC"
photo = "assets/scene/TCC.png"
avatar = "assets/scene/TCC.png"
name = "旁白"
photo = "null"
avatar = "null"
```
（！）event 數量最多1000個

每個event 後面不一定要接子集，如果沒有加backpack 就代表背包內無物品

`character_number`是出現在畫面的角色人數，最多6人，最少0人

有n個character後面會接n個name, photo, favor

`name`是character的名字

`photo`是那個character的立繪

（！）如果是主角或旁白的對話，沒有立繪，直接在photo後面放`"null"`即可

`avatar`是人物頭像，靠腰原本忘記加了 跟photo一樣，如果沒圖片放null即可
### backpack
```toml
[[professor.discussing.backpack]] #每個event後面要再放當下情況的backpack
items_number = 2 #(0~3)
description_box = "assets/backpack/description_box.png"
name = "water bottle"
photo = "assets/backpack/water_bottle.png"
description = "just a cute water bottle"
name = "pencil"
photo = "assets/backpack/pencil.png"
description = "it can write on anything"
```
如果沒出現backpack的子集，就預設背包內無道具

`items_number`是在當下event 背包內的物品數量，最多9項

有幾項物品，後面會接幾個name, photo, discription

`name`就是道具名稱

`photo`是道具圖片

`description`是道具簡介，裡面放string介紹道具功能
### dialogue
```toml
[[professor.discussing.dialogue]] #假如沒讀到就不用處理
dialog_box = "assets/scene/dialog_box.png"
string_number = 3 #(0~100) 0代表沒有對話
speaker = "L紀" #需要判錯是否有這個人物
text = "text1"
speaker = "L紀"
text = "text2"
speaker = "TCC"
text = "text3"
next = [event1]
```
（！）不一定每個event都會有對話

`string_number`代表總共會出現的字串數量

之後有幾條string 就會有幾個speaker, text

`speaker`就是當下在說話的character

`text`就是應該要出現的相對應string

`next`就是在沒有reply的時候要直接結束這個event 要跳到下個event，略過中間可能會出現的子事件

如果有reply 或是沒有要跳轉的事件就在next 後面放`"null"`

（！）注意 如果dialogue.next不是null，後面就不能放reply
#### reply
```toml
[[professor.discussing.reply]] #沒讀到就不用處理
option_box = "assets/scene/option_box.png"
object = "TCC"
option1 = "text1"
change_favor1 = +3 #(-5~+5)
next1 = "[event1]" #connect to other event（被中括號包起來）
option2 = "text2"
change_favor2 = 0 #(-5~+5)
next2 = "[event2]"
option3 = "text3" 
change_favor3 = -5 #(-5~+5)
next3 = "[event3]"
```
dialogue 的子集，如果沒有dialogue 就不會有reply

`option_box`是選項的格子

`object`是改變好感度的對象

`option`是回覆的選項

`change_favor`就是選擇這個`option`會改變`favor`的數值

`next`後面接的是[event]`會直接switch 到下一個event
