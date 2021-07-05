#include<iostream>
#include<opencv2/opencv.hpp>
//#include "my.hpp"
int main()
{
    //получаем изображение1
    cv::Mat img1 = cv::imread("cat1.jpg"); 
    cv::Mat img3, img4, img5; 
    cv::resize(img1, img3, cv::Size(8,8), 0,0); //изменяем размер 
    cv::cvtColor(img3, img4, cv::COLOR_RGB2GRAY ); //переводим в градации серого
    cv::Scalar average = cv::mean(img4); //вычисляем среднее
    cv::threshold(img4, img5, average.val[0], 255, cv::THRESH_BINARY );//если значение больше среднего, присваиваем ему значение 255, если меньше - 0
    int k = 0;
    int arr[63];
    for(int i = 1; i<9; i++)
    {
        for(int j = 1; j<9; j++)
        { 
            int l = img5.at<int>(i-1,j-1);

            if(l==0)
            {
                arr[i*j-1] = 0;
            }
            else
            {
              arr[i*j-1] = 1;
            }
            
        }
    }
    
    //хеш для второго изображения
    //получение картинки 
    cv::Mat imag1 = cv::imread("cat1.jpg"); 
    cv::Mat imag3, imag4, imag5; 
    cv::resize(imag1, imag3, cv::Size(8,8), 0,0); //изменяем размер 
    cv::cvtColor(imag3, imag4, cv::COLOR_RGB2GRAY ); //переводим в градации серого
    cv::Scalar average2 = cv::mean(imag4); //вычисляем среднее
    cv::threshold(imag4, imag5, average2.val[0], 255, cv::THRESH_BINARY );//если значение больше среднего, присваиваем ему значение 255, если меньше - 0
    int d = 0;
    int arr2[63];
    //строим хеш
    for(int i = 1; i<9; i++)
    {
        for(int j = 1; j<9; j++)
        { 
            int r = imag5.at<int>(i-1,j-1);

            if(r==0)
            {
                arr2[i*j-1] = 0;
            }
            else
            {
              arr2[i*j-1] = 1;
            }
            
        }
    }
    
    //расчет расстояния хеминга
    int haming = 0;
    for (int i = 0; i<64; i++)
    {
        if(arr[i]==arr2[i])
        {

        }
        else
        {
            haming++;
        }
       
    }
    std::cout << haming << std::endl;
    return 0;
    

}

