# Rock Paper Scissors Protocol

## Принятые решения для реализации задачи

- `header-only` библиотека
- контракт между `server` и `client`
- исходники
- `include/RockPaperScissorsProtocol`
  - `entity` - сущности, которыми оперируют и `server` и `client`
    - `Card.hpp` - поддерживаемые типы карт, также тут находятся константы для `server` и `client`
    - `Message.hpp` - базовый класс для всех сообщений (нужно для удобного использования)
    - `MessageExecutor.hpp` - парсит запросы|ответы, перенаправляет на `Handler` (обработчики запросов|ответов)
    - `MessageRepresentation.hpp` - представление `типа` сообщения в сериализуемом виде (можно переименовать `MessageTypeRepresentation`)
    - `MessageSender.hpp` - отправитель запросов
    - `client` - сущности для общения с клиентом
      - `ClientMessageType.hpp` - комманды, которые поддерживает `client`
      - `ClientMessageExecutor.hpp` - `alias` на `MessageExecutor`, параметризированный `ClientMessageType`
      - `ClientMessage` - `alias` на `Message`, параметризированный `ClientMessageType`
      - `request` - запросы-сообщения, которые способен обработать `client`
      - `response` - ответы-сообщения, которые `client` способен отправить в ответ на `request`(запрос)
    - `server` - сущности для общения с сервером
      - `ServerMessageType.hpp` - комманды, которые поддерживает `server`
      - `ServerMessageExecutor.hpp` - `alias` на `MessageExecutor`, параметризированный `ServerMessageType`
      - `ServerMessage` - `alias` на `Message`, параметризированный `ServerMessageType`
      - `request` - запросы-сообщения, которые способен обработать `server`
      - `response` - ответы-сообщения, которые `server` способен отправить в ответ на `request`(запрос)
  - `interface` - интерфейсы, которыми оперируют и `server` и `client`
    - `Connection.hpp` - интерфейсы, для представления соединения между `server` и `client`
    - `MessageHandlerBase.hpp` - интерфейс-база для смешивания статического и динамического полиморфизма (для скорости и удобства разработки), нужно для `MessageExecutor`
    - `RequestHandler.hpp` - интерфейс-база отнаследованный от `MessageHandlerBase`, который финализирует виртуальный метод из `MessageHandlerBase` и предоставляет `user-friendly` виртуальный метод для работы
    - `ResponseHandler.hpp` - интерфейс-база отнаследованный от `MessageHandlerBase`, который финализирует виртуальный метод из `MessageHandlerBase` и предоставляет `user-friendly` виртуальный метод для работы
    - `client` - интерфейсы, которые должна реализовать клиентская часть
      - `request` - интерфейсы, `alias` (алиасы) на `RequestHandler`, параметризированные конкретным `ClientMessage`
      - `response` - интерфейсы, `alias` (алиасы) на `ResponseHandler`, параметризированные конкретным `ClientMessage`
    - `server` - интерфейсы, которые должна реализовать серверная часть
      - `request` - интерфейсы, `alias` (алиасы) на `RequestHandler`, параметризированные конкретным `ClientMessage`
      - `response` - интерфейсы, `alias` (алиасы) на `ResponseHandler`, параметризированные конкретным `ClientMessage`
  - `util` - всё что нужно на `server` и `client`, но ни к чему не относится
    - `Util.hpp` - пару функций сериализации, десириализации почти всего и вся. огромный `trade-off` в пользу скорости разработки (из-за ограниченного времени). я понимаю, что это супер медленно. но проект большой, поэтому было решено этим пренибречь.
