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
└── README.md
```
## 基本功能
支援場景、人物、物品、人物頭像、人物立繪、物品圖標、對話選項、支線劇情
## 額外功能
場景動畫、心情變換、音效播放、遊戲存檔
## 遊玩方式
1. 在終端機執行`make`
2. 在`final_project`目錄下執行 `./bin/interactive_novel_engine`
## script 編寫規則
https://hackmd.io/@cyucccx/Hyb8iDmM0
## 素材來源
* UI素材：[空想曲線](https://kopacurve.blog.fc2.com/blog-entry-394.html) 
* 背景素材：[きまぐれアフター背景素材置き場](https://gakaisozai.seesaa.net/article/202102article_1.html)
* 音樂、音效：[魔王魂](https://maou.audio/rule/)
