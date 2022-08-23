<?
/*
 * 概要：Bookオブジェクト
 * 作成者：山崎
 */
class Book{
    /*
     * 書籍データのフィールド変数
     */
    private $isbn;
    private $title;
    private $price;

    /*
     * 概要：コンストラクタ
     */
    public function __construct(){
        $this->init();
    }

    /*
     * 概要：初期化用関数
     */
    public function init(){
        $this->isbn = "";
        $this->title = "";
        $this->price = 0;
    }

    /*
     * 概要：各setterメソッド
     */
    public function setIsbn($param){
        $this->isbn = $param;
    }

    public function setTitle($param){
        $this->title = $param;
    }

    public function setPrice($param){
        $this->price = $param;
    }

    /*
     * 各getterメソッド
     */
    public function getIsbn(){
        return $this->isbn;
    }

    public function getTitle(){
        return $this->title;
    }

    public function getPrice(){
        return $this->price;
    }
}
?>