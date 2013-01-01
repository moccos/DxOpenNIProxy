DxOpenNIProxy
=============

概要
-----
MikuMikuDance (32bit) のKinectインタフェースであるDLL (DxOpenNI.dll)を、動的に選択可能とするDLLです。このDxOpenNI.dllから、別のDxOpenNI.dllをこまめにロードしたり手離したりします。
複数のDLLを使い分けたいユーザー、あるいは開発者向けです。

* Version: 1.20 (2011/01/12)

* 配布場所: (http://www.moccos.info/works/software/mmd.html)[http://www.moccos.info/works/software/mmd.html]
* ソースコード: [https://github.com/moccos/DxOpenNIProxy/](https://github.com/moccos/DxOpenNIProxy/)
* 説明動画: [ニコニコ動画 sm13211158](http://www.nicovideo.jp/watch/sm13211158)


インストールとファイル配置
-----
1. MikuMikuDance.exeの下のDataフォルダに、DxOpenNIProxyフォルダを作成します。
1. 作成したDxOpenNIProxyフォルダに、使用するdllを入れます。
     複数使用する場合は、区別のつくようにリネームしてください。
1. MikuMikuDance.exeの下のDataフォルダに、付属のDxOpenNI.dllを置きます。
1. MikuMikuDance.exeの下のDataフォルダに、DxOpenNIProxy.iniを作成します。文字コードはShift JISにしてください。(Unicode等のワイド文字列は読みません)

インストールとファイル配置
-----
### 設定ファイルの書き方
各行は「ファイル名」「タブ」「(必要なら)*印」の順に記載します。

*印はデフォルトで選択されるものを現します。

*印がないときでも最後にタブを入れてください。(現状の手抜き仕様)

複数*印つきがあるときは、一番下のものが優先です。
日本語ファイル名は試したことがありません…

    (例)
    DxOpenNI_nene.dll[Tab]	
    DxOpenNI_manaka.dll[Tab]
    DxOpenNI_rinko.dll[Tab]

上の例で[Tab]の部分はタブ文字を表します。

操作方法
-------
- MMDから普通にKinectメニューを選択した場合、設定ファイルで*印のついたdllが使われます。前述の例だとDxOpenNI_manaka.dllが使われます。

- Shiftを押しながらKinectメニューを選択すると、選択用のダイアログが出て
設定ファイルに記述されたものの中から選択することが出来ます。

今後の予定
-------
ダイアログで選択したものを新しいデフォルトにするとか、
dll名と同じ名前のテキストファイルを開けるボタンをつけるとか
アイデアはありますが、今のところユーザーが自分だけなので、後回しになりそうです。
平滑化等のフィルタ系の動作をするものなら、同時使用できる意味もあるかも。等々。

開発者向け情報
-------
* 序数による呼び出しを使っているので、Exportした関数の並びがオリジナルのDxOpenNI.dllと違っているとセグります。
以下に示す並びを想定。

    [0] ?OpenNIClean@@YGXXZ
    [1] ?OpenNIDepthTexture@@YGXPAPAUIDirect3DTexture9@@@Z
    [2] ?OpenNIDrawDepthMap@@YGX_N@Z
    [3] ?OpenNIGetSkeltonJointPosition@@YGXHPAUD3DXVECTOR3@@@Z
    [4] ?OpenNIGetVersion@@YGXPAM@Z
    [5] ?OpenNIInit@@YG_NPAUHWND__@@_NPAUIDirect3DDevice9@@PA_W@Z
    [6] ?OpenNIIsTracking@@YGXPA_N@Z

* 古いバージョンのDLLの読み込み

GetVersionの値を見て、MMD最新バージョンに合わせた挙動をエミュレートするために
いくつか独自の動作をさせています。

* version 1.10のDLL

BP_Vector[15]が無いので、BP_Vector[0] (センター)を返すようにしています。
oniファイル読み込み機能が無いので、ファイル読み込みをさせると常に失敗を返します。

# ライセンス / License
-[GNU LESSER GENERAL PUBLIC LICENSE version 3](http://www.gnu.org/copyleft/lesser.html)

- ------
作者
-------
* もっこす (moccos)
 * Twitter: [@moccos](https://twitter.com/moccos)
 * はてな: [id:moccos_info](http://d.hatena.ne.jp/moccos_info/)