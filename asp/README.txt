
	TOPPERS/ASP Kernel（Release 1.3.2）
		Toyohashi Open Platform for Embedded Real-Time Systems/
		Advanced Standard Profile Kernel

TOPPERS/ASPカーネル（以下，ASPカーネル）は，TOPPERS新世代カーネルの基盤
（出発点）となるものとして，TOPPERSプロジェクトにおいて開発したリアルタ
イムカーネルです．μITRON4.0仕様のスタンダードプロファイル準拠のリアル
タイムカーネルであるTOPPERS/JSPカーネルを拡張・改良する形で開発しました．

【最初に読むべきドキュメント】

ASPカーネルのユーザーズマニュアルが，doc/user.txtにあります．ASPカーネ
ルを使用する場合には，まずはこのドキュメントからお読み下さい．

【ファイルの閲覧にあたって】

ASPカーネルのドキュメント（プレーンテキストファイル）およびソースファイ
ルを読む際には，TABを4に設定してください．

【利用条件】

ASPカーネルの利用条件は，各ファイルの先頭に表示されているTOPPERSライセ
ンスです．TOPPERSライセンスに関するFAQが，以下のページにあります．

	http://www.toppers.jp/faq/faq_ct12.html

【質問・バグレポート・意見等の送付先】

ASPカーネルをより良いものにするためのご意見等を歓迎します．ASPカーネル
に関する質問やバグレポート，ご意見等は，TOPPERSプロジェクトの会員は
TOPPERS開発者メーリングリスト（dev@toppers.jp）宛に，その他の方は
TOPPERSユーザーズメーリングリスト（users@toppers.jp）宛にお願いします．

TOPPERSユーザーズメーリングリストへの登録方法については，以下のページに
説明があります．

	http://www.toppers.jp/community.html

【ポーティングにあたって】

ASPカーネルを，TOPPERSプロジェクトからオープンソースにすることを前提に，
未サポートのターゲットにポーティングされる場合には，あらかじめご相談く
ださると幸いです．

【今後の改造計画】

今後（Release 1.4以降），ASPカーネルに対して大きな変更が予想される箇所
は次の通りです．

・TOPPERS組込みコンポーネントシステム（TECS）の導入．デバイスドライバや
　システムログ機能との接続にTECSを用いることを検討しています．

以上
