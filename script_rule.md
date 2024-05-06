# script 編寫規則

```
.
├── name and author
├── home
└── event
    ├── dialogue
    |   └── reply
    └── backpack
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
```
`[home]`是設定主畫面的小標

`background`是主畫面的背景

`button`是選擇遊戲開始的按鍵

`backpack_ground`在這裡先設定背包畫面的背景

## event
```toml
[professor.discussing] #event #中間不能空格
background = "assets/scene/background.png"
backpack_icon = "assets/scene/backpack_icon.png"
character_number = 2 #(0~3)
name = "L紀"
photo = "assets/scene/L紀.png"
favor = -2 #(-9~+9)
name = "TCC"
photo = "assets/scene/TCC.png"
favor = +5 #(-9~+9)
```
（！）event 數量最多1000個

每個event 後面不一定要接子集，如果沒有加backpack 就代表背包內無物品

`character_number`是出現在畫面的角色人數，最多3人，最少0人

有n個character後面會接n個name, photo, favor

`name`是character的名字

`photo`是那個character的立繪

`favor`是在這個event裡，相對應character的好感度
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
```
（！）不一定每個event都會有對話

`string_number`代表總共會出現的字串數量

之後有幾條string 就會有幾個speaker, text

`speaker`就是當下在說話的character

`text`就是應該要出現的相對應string
#### reply
```toml
[[professor.discussing.reply]] #沒讀到就不用處理
option_box = "assets/scene/option_box.png"
option1 = "text1"
next1 = "[event1]" #connect to other event（被中括號包起來）
option2 = "text2"
next2 = "[event2]"
option3 = "text3" 
next3 = "[event3]"
```
dialogue 的子集，如果沒有dialogue 就不會有reply

`option`是回覆的選項

`next`後面接的是`[event]`會直接switch 到下一個event
### backpack
```toml
[[professor.discussing.backpack]] #每個event後面要再放當下情況的backpack
items_number = 5 #(0~9)
name = "water bottle"
photo = "assets/backpack/water_bottle.png"
description = "just a cute water bottle"
name = "pencil"
photo = "assets/backpack/pencil.png"
description = "it can write on anything"
name = "T-shirt"
photo = "assets/backpack/T-shirt.png"
description = "it is too small to L紀"
name = "watch"
photo = "assets/backpack/watch.png"
description = "apple watch, very expensive"
name = "christmas tree"
photo = "assets/backpack/christmas_tree.png"
description = "hahahappy christmas"
```
如果沒出現backpack的子集，就預設背包內無道具

`items_number`是在當下event 背包內的物品數量，最多9項

有幾項物品，後面會接幾個name, photo, discription

`name`就是道具名稱

`photo`是道具圖片

`description`是道具簡介，裡面放string介紹道具功能
