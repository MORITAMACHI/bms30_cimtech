<?php
//====================================================================================================
//  システム名：
//    書籍管理システム(Web版Ver.1.5)
//  サブシステム名：
//      共通
//  モジュール名：
//      db.inc  データベース関連モジュール
//  説明：
//      DB用関数群
//  バージョン情報：
//      作成日）2010/03/29
//      作成者）h.yamamoto
//      変更日）
//      変更者）
//  備考
//      DB関連
//====================================================================================================
include_once dirname(__FILE__).'/mysql.inc';

//DB定数
define('MYSQL_HOST',$db_host);
define('MYSQL_ID',$db_user);
define('MYSQL_PASS',$db_passwd);
define('MYSQL_DB',$db_name);

/* ********** DB関連 ********** */
//====================================================================================================
//  概要：
//    connectDatabase
//  機能説明：
//    データベースに接続する。
//  引数：
//    $db： コネクションID
//  戻り値
//    True：処理成功  False：処理失敗
//  備考：
//      作成日）2010/03/29
//      作成者）h.yamamoto
//      変更日）
//      変更者）
//      変  更）
//====================================================================================================
	function connectDatabase(&$db) {
		try{
			$db = @mysqli_connect(MYSQL_HOST,MYSQL_ID,MYSQL_PASS) or die("MySQLの接続に失敗しました。".mysqli_errno().": ".mysqli_error());
			if (! $db ) {
				return false;
			}else{
				//DB選択

				@mysqli_select_db($db, MYSQL_DB) or die("データベースの接続に失敗しました。" . mysqli_errno($db) . ": " . mysqli_error($db));
				return true;
			}
		}catch(Exception $e){
			return false;
		}
	}

//====================================================================================================
//  概要：
//    closeDatabase
//  機能説明：
//    データベースを切断する。
//  引数：
//    $db： コネクションID
//  戻り値
//    True：処理成功  False：処理失敗
//  備考：
//      作成日）2010/03/29
//      作成者）h.yamamoto
//      変更日）
//      変更者）
//      変  更）
//====================================================================================================
	function closeDatabase(&$db) {
		if (!$db){
			return true;
		}else{
			$return = @mysqli_close($db)or die("MySQL切断に失敗しました。" . mysqli_errno($db).": " . mysqli_error($db));
			if ($return == false) {
				return false;
			}
		}
		return true;
	}

	/** dbprocess.phpの代わりに追加
	 *
	 * @param  $db
	 * @param  $sql
	 * @return $result 0またはbooleanを返す
	 */
	function executeQuery($db,$sql)
	{
	    connectDatabase($db);

	    // クエリを送信する
	    $result = @mysqli_query($db, $sql) or die("クエリの送信に失敗しました。SQL:" . $sql);

	    // MySQLへの接続を閉じる
	    @mysqli_close($db) or die("MySQL切断に失敗しました。>>");

	    // 戻り値
	    return ($result);
	}
