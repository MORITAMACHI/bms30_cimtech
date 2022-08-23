<?php
/*
 *  showSalesByMonthで使用するためのDTOクラス
 *  作成者：たけだ
 *  作成日：2022/08/20
 */

class Sales {
    // フィールド変数
    private $isbn;
    private $title;
    private $price;
    private $totalQuantity;
    private $subTotalSales;

    // コンストラクタ
    public function __construct(){
         $this->isbn = 0;
         $this->title="";
         $this->price=0;
         $this->totalQuantity=0;
         $this->subTotalSales=0;
    }


    /**
     * アクセサメソッド
     */
    public function getIsbn()
    {
        return $this->isbn;
    }

    public function getTitle()
    {
        return $this->title;
    }

    public function getPrice()
    {
        return $this->price;
    }

    public function getTotalQuantity()
    {
        return $this->totalQuantity;
    }

    public function getSubTotalSales()
    {
        return $this->subTotalSales;
    }

    public function setIsbn($isbn)
    {
        $this->isbn = $isbn;
    }

    public function setTitle($title)
    {
        $this->title = $title;
    }

    public function setPrice($price)
    {
        $this->price = $price;
    }

    public function setTotalQuantity($totalQuantity)
    {
        $this->totalQuantity = $totalQuantity;
    }

    public function setSubTotalSales($subTotalSales)
    {
        $this->subTotalSales = $subTotalSales;
    }


}

?>
