<?php
/*
 * システム名：update.inc
 * 説明：書籍更新画面項目クラス
 * 作成日：2022/08/23
 * 作成者：貝谷和則
 */

class UpdateBook{

    //フィールド変数の定義
    private $isbn;  //ISBN
    private $title;  //タイトル
    private $price;  //価格
    private $bookInfo;  //書籍情報
    private $execute;  //処理種別

    //コンストラクタ
    public function __construct(){
        $this->init();
    }
    //フィールド変数の初期化
    public function init(){
        $this->isbn = "";
        $this->title = "";
        $this->price = "";
        $this->bookInfo = "";
        $this->execute = "";
    }
    //セッターメソッド
    public function setIsbn($param){
        $this->isbn = $param;
    }
    public function setTitle($param){
        $this->title = $param;
    }
    public function setPrice($param){
        $this->price = $param;
    }
    public function setBookInfo($param){
        $this->bookInfo = $param;
    }
    public function setExecute($param){
        $this->execute = $param;
    }
    //ゲッターメソッド
    public function getIsbn(){
        return $this->isbn;
    }
    public function getTitle(){
        return $this->title;
    }
    public function getPrice(){
        return $this->price;
    }
    public function getBookInfo(){
        return $this->bookInfo;
    }
    public function getExecute(){
        return $this->execute;
    }

    public function getForm() {
        //ISBN
        if (isset($_POST['isbn'])){
            $this->isbn=$_POST['isbn'];
        }else if(isset($_GET['isbn'])){
            $this->isbn=$_GET['isbn'];
        }
        //タイトル
        if (isset($_POST['title'])){
            $this->title=htmlspecialchars($_POST['title'],ENT_QUOTES,"sjis");
        }
        //価格
        if (isset($_POST['price'])){
            $this->price=$_POST['price'];
        }
        //書籍一覧
        if (isset($_POST['bookInfo'])){
            $this->booklist=$_POST['bookInfo'];
        }
        //処理種別
        if (isset($_POST['execute'])){
            $this->execute=$_POST['execute'];
        }
    }
    public function processing($db) {
        //変更対象の書籍情報を取得する
        $this->searchIsbn($db);
        //処理種別を判定
        if($this->getExecute() == ""){
            /* 初期遷移処理 */

            //変更対象データが取得出来たか判断
            if($this->getBookInfo() == null){
                //エラーメッセージを設定
                $errMsg = "更新対象の書籍は存在しない為、更新処理は行なえませんでした。ここ！";

                //エラー画面へ遷移する
                callErrorPage($errMsg);

                exit;

            }else{
                //初期表示用のタイトルと価格をセットする
                //$book = $this->getBookInfo();
                //$this->setTitle($book[title]);
                //$this->setPrice($book[price]);
            }

        }else{
            /* 変更完了ボタン押下からの処理 */
            //変更対象データが取得出来たか判断
            if($this->getBookInfo() == null){
                //エラーメッセージを設定
                $errMsg = "更新対象の書籍は存在しない為、更新処理は行なえませんでした。ボタンは押せた";

                //エラー画面へ遷移する
                callErrorPage($errMsg);

                exit;
            }

            //更新処理を実行
            $this->update($db);
        }
    }
    public function searchIsbn($db){
        $sql  = "";
        $row  = null;

        //抽出SQL生成
        $sql  = "SELECT *";
        $sql .= " FROM bookinfo";
        $sql .= " WHERE ISBN =".createSqlString($this->isbn);

        //SQL文の表示
        //echo $sql;

        //SQL発行
        $result = mysqli_query($db, $sql);

        //該当ISBNデータを取得
        $this->bookInfo = mysqli_fetch_assoc($result);

        //リソースの開放
        mysqli_free_result($result);

    }
    public function update($db){
        $sql  = "";
        $row  = null;

        //抽出SQL生成
        $sql  = "UPDATE bookinfo SET";
        $sql .= " TITLE=".createSqlString($this->title).",";
        $sql .= " PRICE=".$this->price;
        $sql .= " WHERE ISBN=".createSqlString($this->isbn);

        //SQL文の表示
        //echo $sql;

        //SQL発行
        $result = mysqli_query($db, $sql);

    }
}
?>
