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

    //isbnゲッター
    public function getIsbn(){
        return $this->isbn;
    }
    //isbnセッター
    public function setIsbn($isbn){
        $this->isbn = $isbn;
    }
    //titleゲッター
    public function getTitle(){
        return $this->title;
    }
    //titleセッター
    public function setTitle($title){
        $this->title = $title;
    }
    //priceゲッター
    public function getPrice(){
        return $this->price;
    }
    //priceセッター
    public function setPrice($price){
        $this->price = $price;
    }
    //quantityゲッター
    public function getQuantity(){
        return $this->quantity;
    }
    //quantityセッター
    public function setIsbn($quantity){
        $this->quantity = $quantity;
    }
}



?>
