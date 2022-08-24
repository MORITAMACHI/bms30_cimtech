<?php
/*
 * システム名：書籍管理システムWeb版Ver.3.0
 * サブシステム名：書籍一覧画面
 * 説明：書籍一覧画面項目クラス
 * 作成日：2022/08/22
 * 作成者：貝谷和則
 */


class ListBook{
    //フィールド変数
    private $isbn;
    private $title;
    private $price;
    private $bookList;
    private $execute;

    //コンストラクタ
    public function __construct(){
        $this->init();
    }

    //初期化
    public function init(){
        $this->isbn = '';  //ISBN
        $this->title = '';  //タイトル
        $this->price = '';  //価格
        $this->bookList = '';  //書籍一覧
        $this->execute = '';  //処理種別
    }
    //セッターメソッド
    //ISBN
    public function setIsbn($parm){
        $this->isbn= $param;
    }
    //タイトル
    public function setTitle($param){
        $this->title= $param;
    }
    //価格
    public function setPrice($param){
        $this->price= $param;
    }
    //書籍一覧
    public function setBookList($param){
        $this->bookList= $param;
    }
    //処理種別
    public function setExecute($param){
        $this->execute= $param;
    }
    //ゲッターメソッド
    //ISBN
    public function getIsbn(){
        return $this->isbn;
    }
    //タイトル
    public function getTitle(){
        return $this->title;
    }
    //価格
    public function getPrice(){
        return $this->price;
    }
    //書籍一覧
    public function getBookList(){
        return $this->bookList;
    }
    //処理種別
    public function getExecute(){
        return $this->execute;
    }
    //データ取得のためのメソッド
    public function getForm() {
        //ISBN
        if (isset($_POST['isbn'])){
            $this->isbn=$_POST['isbn'];
        }
        //タイトル
        if (isset($_POST['title'])){
            $this->title=$_POST['title'];
        }
        //価格
        if (isset($_POST['price'])){
            $this->price=$_POST['price'];
        }
        //書籍一覧
        if (isset($_POST['booklist'])){
            $this->bookList=$_POST['booklist'];
        }
        //処理種別
        if (isset($_POST['execute'])){
            $this->execute=$_POST['execute'];
        }
    }
    //書籍一覧表示処理
    public function processing($db) {
        //処理種別を判定
        if($this->getExecute() == "検索"){
            /* 検索ボタン押下からの処理 */
            //絞込み検索を行なう
            $this->select($db);

        }else{
            /* 初期表示又は全件表示ボタン押下からの処理 */
            //書籍一覧を全検索を行なう
            $this->selectAll($db);

        }
    }
    //全検索
    public function selectAll($db){
        $sql  = "";
        $row  = null;
        $rows = null;
        $cnt  = 0;

        //抽出SQL生成
        $sql  = "SELECT * FROM bookinfo ORDER BY ISBN";

        //SQL文の表示
        //echo $sql;

        //SQL発行
        $stid = mysqli_query($db, $sql);

        //データ抽出
        //抽出件数文配列に格納する
        while($row = mysqli_fetch_assoc($stid))
        {
            foreach($row as $key => $value)
            {
                $rows[$cnt][] = $value;
            }
            ++$cnt;
        }
        $this->bookList = $rows;

        //リソースの開放
        mysqli_free_result($stid);
    }
    //絞り込み検索
    public function select($db){
        $sql  = "";
        $row  = null;
        $rows = null;
        $cnt  = 0;

        //抽出SQL生成
        $sql  = "SELECT * FROM bookinfo ";
        $sql .= "WHERE ISBN  like '%".createNullHtmlString($this->isbn)."%'  OR";
        $sql .= "      TITLE like '%".createNullHtmlString($this->title)."%' OR";
        $sql .= "      PRICE like '%".createNullHtmlString($this->price)."%'";
        $sql .= " ORDER BY ISBN";

        //SQL文の表示
        //echo $sql;

        //SQL発行
        $result = mysqli_query($db, $sql);

        //データ抽出
        //抽出件数文配列に格納する
        while($row = mysqli_fetch_assoc($result))
        {
            foreach($row as $key => $val)
            {
                $rows[$cnt][] = $val;
            }
            ++$cnt;
        }
        $this->bookList = $rows;

        //リソースの開放
        mysqli_free_result($result);
    }

}
?>


