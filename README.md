重点关注：
03C语言和设计模式_状态模式
UI必备。

15C语言和设计模式_代理模式
通信必备

10C语言和设计模式_中介者模式
	中介者模式的本质：解耦多个同事对象之间的交互关系，每个对象都持有中介者对象的引用。只跟中介者对象打交道。
	通过中介者对象统一管理这些交互对象。

12C语言和设计模式_适配器模式
适配器模式：让我们先模拟一下适配器模式的真实使用场景：一家互联网金融公司A，开发了一套股票交易系统，其包含客户端和服务器，用户登录接口是由客户端和服务器端自主协商的，目前这套系统已投入生产并稳定运行。某天，公司A接到一家证券公司的项目，需要把这套系统部署在这个证券公司中。此外，此证券公司还同时使用了公司B的客户端，因此，公司B的客户端需与公司A的服务器端相接。但公司B客户端的用户信息与公司a系统定义的类型不符，这时，该怎么办呢？
有三种解决方案。一，修改服务器的接口，以适应其他客户端的用户类型。二，增加接口，以处理另一个客户端的用户类型。三，在服务端执行用户处理接口前，调用一个方法，把其他客户端的用户类型转换成原本的用户类型。
方案一的缺点是他会修改到已经在生产环境上稳定运行的接口，影响系统的稳定性，且需要进行回归测试。方案二的缺点是，新增加的接口的业务逻辑会与原来的接口有所重复。而方案三即是适配器模式，它不仅有效地解决了问题，同时避免了前两种方案的弊端。
什么时候需要用适配器模式？只要记住一点。当你有动机修改一个已经投入生产的接口，这时候就可以考虑试用适配器模式。适配器模式是用于解决接口不兼容问题有效方法。

07C语言和设计模式_观察者模式

04C语言和设计模式_命令模式
