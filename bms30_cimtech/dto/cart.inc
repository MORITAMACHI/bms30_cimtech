<?php
//=====================================================================================
// プログラム名  ：cart.inc
// プログラム説明：カート内容確認の際に使用するDTOファイル
// 作成者        ：貝谷和則
// 作成日        ：2022/08/22
//=====================================================================================

class Cart{
    //フィールド変数を定義
    private $isbn;
    private $title;
    private $price;
    private $quantity;

    //コンストラクタ
    public function __construct(){
        $this->init();
    }

    //フィールド変数初期化
    public function init(){
        $this->isbn = null;
        $this->title = null;
        $this->price = null;
        $this->quantity = null;
    }


    //isbnゲッター
    public function getIsbn(){
        return $this->isbn;
    }
    //titleゲッター
    public function getTitle(){
        return $this->title;
    }
    //priceゲッター
    public function getPrice(){
        return $this->price;
    }
    //quantityゲッター
    public function getQuantity(){
        return $this->quantity;
    }
    //isbnセッター
    public function setIsbn($isbn){
        $this->isbn = $isbn;
    }

    //titleセッター
    public function setTitle($title){
        $this->title = $title;
    }
    //priceセッター
    public function setPrice($price){
        $this->price = $price;
    }
    //quantityセッター
    public function setQuantity($quantity){
        $this->quantity = $quantity;
    }
}



?>
