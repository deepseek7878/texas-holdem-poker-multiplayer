Designed for low-latency real-time multiplayer poker systems.
# Texas Hold'em Poker Multiplayer Server App

[![GitHub stars](https://img.shields.io/github/stars/deepseek7878/texas-holdem-poker-multiplayer?style=for-the-badge)](https://github.com/deepseek7878/texas-holdem-poker-multiplayer)
[![GitHub forks](https://img.shields.io/github/forks/deepseek7878/texas-holdem-poker-multiplayer?style=for-the-badge)](https://github.com/deepseek7878/texas-holdem-poker-multiplayer)
[![GitHub issues](https://img.shields.io/github/issues/deepseek7878/texas-holdem-poker-multiplayer?style=for-the-badge)](https://github.com/deepseek7878/texas-holdem-poker-multiplayer/issues)
[![GitHub pull requests](https://img.shields.io/github/issues-pr/deepseek7878/texas-holdem-poker-multiplayer?style=for-the-badge)](https://github.com/deepseek7878/texas-holdem-poker-multiplayer/pulls)
[![License](https://img.shields.io/github/license/deepseek7878/texas-holdem-poker-multiplayer?style=for-the-badge)](https://github.com/deepseek7878/texas-holdem-poker-multiplayer/blob/main/LICENSE)

Open-source Texas Hold'em multiplayer poker game / 開源德州撲克多人遊戲 / 开源德州扑克多人游戏, built for real-time rooms, game state synchronization, and easy local deployment.

## Overview / 概述 / 概覽
This project is a multiplayer Texas Hold'em poker game server application / 这是一个多人德州扑克游戏服务端项目 / 這是一個多人德州撲克遊戲服務端專案.  
It focuses on room-based matches, real-time updates, and a clean code structure for learning, customization, and extension / 它专注于房间制对局、实时同步和清晰的代码结构，适合学习、定制和扩展 / 它專注於房間制對局、即時同步和清晰的程式結構，適合學習、客製化與擴展.

## Key Features / 核心功能 / 核心功能
- Real-time multiplayer gameplay / 实时多人游戏体验 / 即時多人遊戲體驗.
- Room creation and room joining / 创建房间与加入房间 / 建立房間與加入房間.
- Game state synchronization across players / 玩家之间的游戏状态同步 / 玩家之間的遊戲狀態同步.
- Betting rounds, showdown, and pot settlement / 下注轮、摊牌与底池结算 / 下注輪、攤牌與底池結算.
- Hand evaluation and round management / 牌型判断与回合管理 / 牌型判斷與回合管理.
- Clean and extensible architecture / 结构清晰，便于二次开发 / 結構清晰，便於二次開發.
- Suitable for learning and building custom poker products / 适合学习和构建自定义扑克项目 / 適合學習與建立自訂撲克專案.
## 🎮 Demo Preview

- Gameplay screenshots  
- Server logs preview  
- Multiplayer session example
## 🧠 Technical Highlights

- Low-latency real-time synchronization  
- Server-authoritative state management  
- Action validation & consistency  
- Scalable concurrent session design  
## 💰 获取完整源码
📱 Telegram：@fox_lovemyself
📧 Email：lihongbo9414@gmail.com
👉 联系我获取演示视频 + 详细报价
## Demo / 演示 / 示範
![4房间2-6人桌](https://github.com/user-attachments/assets/f693e475-60cc-43c9-ac03-61f9b2f88e13)
![E64F04E41E05A6173D7344F654CBCF03](https://github.com/user-attachments/assets/e5ea372a-c521-4745-a5e5-44cad236acbb)
![微信图片_20260325214400](https://github.com/user-attachments/assets/57956164-3272-415c-aa81-5e992d876bc0)
![微信图片_20260325214354](https://github.com/user-attachments/assets/9ffb649d-9bd5-4965-b572-94836cabaf9b)
![微信图片_20260325214349](https://github.com/user-attachments/assets/7047966e-12af-4a66-ba56-26be6448c2e7)
![微信图片_20260325214344](https://github.com/user-attachments/assets/4db58ffe-f91a-4809-80c9-93a3de904a49)
![微信图片_20260325214338](https://github.com/user-attachments/assets/26f7be22-d2ea-41c9-b2cc-5287a3019f79)
## Quick Start / 快速开始 / 快速開始
1. Clone the repository / 克隆仓库 / 複製倉庫.
2. Install dependencies / 安装依赖 / 安裝依賴.
3. Configure environment variables if needed / 如有需要请配置环境变量 / 如有需要請設定環境變數.
4. Start the server / 启动服务端 / 啟動服務端.
5. Open the client or browser interface / 打开客户端或浏览器页面 / 開啟客戶端或瀏覽器頁面.

## Installation / 安装 / 安裝
```bash
git clone https://github.com/deepseek7878/texas-holdem-poker-multiplayer.git
cd texas-holdem-poker-multiplayer
npm install
```

If your project uses another package manager, replace the command above with your actual setup / 如果你的项目使用其他包管理器，请替换为实际命令 / 如果你的專案使用其他套件管理器，請替換為實際指令.

## Running the Project / 运行项目 / 執行專案
```bash
npm run dev
```

If you have separate server and client commands, use the following pattern / 如果你的项目有单独的服务端和客户端命令，可以使用下面这种格式 / 如果你的專案有獨立的服務端與客戶端指令，可使用以下格式:

```bash
npm run server
npm run client
```

or / 或 / 或:

```bash
npm run start
```

## Environment Variables / 环境变量 / 環境變數
Create a `.env` file if needed / 如果需要，请创建 `.env` 文件 / 如有需要，請建立 `.env` 檔案.

```env
PORT=3000
HOST=0.0.0.0
NODE_ENV=development
```

Add any project-specific values here / 如有项目专属配置，请在这里补充 / 如有專案專屬設定，請在這裡補充.

## Project Structure / 项目结构 / 專案結構
```text
server/    Backend game server / 后端游戏服务 / 後端遊戲服務
client/    Frontend UI / 前端界面 / 前端介面
shared/    Shared game logic / 共享游戏逻辑 / 共享遊戲邏輯
docs/     Documentation and examples / 文档与示例 / 文件與範例
assets/    Images, icons, and media / 图片、图标和媒体 / 圖片、圖示與媒體
```

## Gameplay Flow / 游戏流程 / 遊戲流程
1. Player enters the lobby / 玩家进入大厅 / 玩家進入大廳.
2. Player creates or joins a room / 玩家创建或加入房间 / 玩家建立或加入房間.
3. Game starts when enough players join / 人数足够后开始游戏 / 人數足夠後開始遊戲.
4. Cards are dealt and betting rounds begin / 发牌并开始下注轮 / 發牌並開始下注輪.
5. Players act in turn / 玩家依次行动 / 玩家依序行動.
6. Showdown determines the winner / 摊牌决定胜负 / 攤牌決定勝負.
7. Pot is settled and next round begins / 结算底池并进入下一局 / 結算底池並進入下一局.

## Use Cases / 适用场景 / 適用場景
- Learn how Texas Hold'em logic works / 学习德州扑克规则和逻辑 / 學習德州撲克規則與邏輯.
- Build a poker room or multiplayer game server / 搭建扑克房间或多人游戏服务端 / 搭建撲克房間或多人遊戲伺服器.
- Customize the game for a private platform / 为私有平台进行定制 / 為私有平台進行客製化.
- Extend into matchmaking, tournaments, or mobile support / 扩展为匹配、锦标赛或移动端支持 / 擴展為配對、錦標賽或行動端支援.

## API or Event Notes / 接口或事件说明 / 介面或事件說明
If your project uses socket events or API endpoints, document them here / 如果项目使用 socket 事件或 API 接口，请在这里说明 / 如果專案使用 socket 事件或 API 端點，請在這裡說明.

Example / 示例 / 範例:
- `create_room`
- `join_room`
- `start_game`
- `player_action`
- `game_update`
- `showdown`
- `game_over`

## Screenshots / 截图 / 截圖
Add gameplay screenshots here / 在这里添加游戏截图 / 在這裡新增遊戲截圖.

## FAQ / 常见问题 / 常見問題
### 1. How do I run the project? / 如何运行项目？ / 如何執行專案？
Install dependencies and run the start command defined in your project / 安装依赖后运行项目定义的启动命令 / 安裝依賴後執行專案定義的啟動指令.

### 2. Is this project open source? / 这是开源项目吗？ / 這是開源專案嗎？
Yes, this project is intended to be open source / 是的，这个项目适合以开源方式发布 / 是的，這個專案適合以開源方式發布.

### 3. Can I customize the rules? / 我可以修改规则吗？ / 我可以修改規則嗎？
Yes, the code structure is designed to be extensible / 可以，代码结构设计为便于扩展 / 可以，程式結構設計為便於擴充.

### 4. Can I use this for commercial or private deployment? / 可以用于商业或私有部署吗？ / 可以用於商業或私有部署嗎？
Check the LICENSE file and your own deployment requirements / 请根据 LICENSE 和你的部署需求决定 / 請根據 LICENSE 與你的部署需求決定.

## Contributing / 贡献 / 貢獻
Pull requests and issues are welcome / 欢迎提交 PR 和 Issue / 歡迎提交 PR 與 Issue.

1. Fork the repository / Fork 仓库 / Fork 倉庫.
2. Create a new branch / 创建新分支 / 建立新分支.
3. Make your changes / 提交修改 / 提交修改.
4. Open a pull request / 发起 PR / 發起 PR.

## Changelog / 更新日志 / 更新日誌
### v1.0.0
- Initial release / 初始版本 / 初始版本.
- Basic multiplayer Texas Hold'em gameplay / 基础多人德州扑克功能 / 基礎多人德州撲克功能.

## License / 许可证 / 授權
Add your license here / 请在这里填写 License / 請在這裡填寫 License.
