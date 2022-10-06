﻿using PovarenokApp.Data;
using PovarenokApp.Scripts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PovarenokApp.Pages
{
    /// <summary>
    /// Логика взаимодействия для CartPage.xaml
    /// </summary>
    public partial class CartPage : Page, IPage
    {
        private List<CartProduct> products = new List<CartProduct>();
        private static CartPage instance;

        public CartPage()
        {
            InitializeComponent();
            instance = this;
        }

        public void Enable()
        {
            UpdateCart();
        }
        public void Disable()
        {

        }

        public static void AddProduct(ProductEntity product)
        {
            var index = instance.products.FindIndex((CartProduct cp) => { return cp.id == product.id; });
            if (index == -1)
            {
                if (product.quantity_in_stock > 0)
                {
                    instance.products.Add(new CartProduct() { id = product.id, quantity = 1 });
                }
                else
                {
                    MessageBox.Show("Товара на складе нету");
                }
            }
            else
            {
                if (product.quantity_in_stock > instance.products[index].quantity)
                {
                    instance.products[index].quantity++;
                }
                else
                {
                    MessageBox.Show("Товар на складе кончился");
                }
            }
        }
        public void UpdateCart()
        {
            List<ProductEntity> productEntities = new List<ProductEntity>();
            for (int i = 0; i < products.Count; i++)
            {
                var product = ApplicationContextDB.Products.FirstOrDefault((ProductEntity p) => { return p.id == products[i].id; }).DeepCopy();
                if (!product.IsEmpty())
                {
                    product.quantity_in_stock = products[i].quantity;
                    product.cost *= product.quantity_in_stock;
                    productEntities.Add(product);
                }
            }
            LViewServices.ItemsSource = null;
            LViewServices.ItemsSource = productEntities;
        }

        private void BackBtn_Click(object sender, RoutedEventArgs e)
        {
            MainWindow.OpenPage(1);
        }

        private void CreateOrder_Click(object sender, RoutedEventArgs e)
        {
            LViewServices.ItemsSource = null;
            ApplicationContextDB.CreateOrder(products);
            products.Clear();

            MessageBox.Show("Ваш заказ был создан!", "Уведомление", MessageBoxButton.OK, MessageBoxImage.Information);
            MainWindow.OpenPage(1);
        }

        private void DeleteBtn_Click(object sender, RoutedEventArgs e)
        {
            var product = (ProductEntity)(sender as Button).DataContext;
            products.Remove(products.Find((CartProduct p) => { return p.id == product.id; }));
            UpdateCart();
        }
    }
}
