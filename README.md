# graphics
# 运行代码
各位在clone完代码后，请自己创建一个gluthead.h的文件，将你电脑中glut该怎么include打进去，这个文件会被ignore掉不会上传。

# 基本思路
文件中将会有一个变量叫objectList，我们程序中所有的Object都会在这个Object中，每一帧，我们会绘画objectList中的每一个object，并且我们会执行每个object的一个脚本。
# Object
object 是我们这个引擎所有对象的父类，他有如下属性以及函数：

1. location ：(x,y,z)（相对父亲的位置，没有父亲就是世界坐标）
2. rotate(x,y,z)
3. size(x,y,z)
4. bool visible；
5. Vector<Object> child; 这个object的child，这样就可以将几个基本元素打包显示了，比如一个桌子有几个桌角和一个桌面）
4. virtual void script()；（在父类中这个是空函数，子类可以重写）
5. virtual void draw（）；（在父类中这个时空函数，子类必须重写）
6. virtual clicked()；（父类为空，子类可以重写）
	
	这个函数的调用机制是：在全局响应到鼠标点击后，通过世界坐标转换，扫描每一个object，发现在范围内就调用（可能还有更好的方法）
# camera

camera 是一个基本的类，我们可以特别定义他，他同样继承自object。我们通过换算，来调用perspective函数，同样要继承于Object。

# canvas 

这个我特别提一下，这个是需要显示在2维平面上的一个东西，相当于在屏幕上直接画的东西，用作菜单啊，按钮啊，字幕这种，这一套还可以好好设计下。

# 其他基本物品的实现。
我们引擎中要实现一些物品，比如立方体，之类的，我们应该让他们继承自Object，然后重写他的draw（）函数。
我们在编写游戏时，如果想要用一个带有脚本的立方体比如，我们就新建一个类，继承立方体的类，然后重写script函数即可。

#例子
我在工程中给每个人建了一个cpp，可以认为这是开发游戏时候你的主函数，现在我在引擎中新建了一个基本的物体（三角体），可以看看我们怎么使用。首先我在我的主函数中，添加了triangle，然后我们就可以发现能够看到我们添加的triangle了，然后我继承了triangle这个类，新建了一个叫rotatingtriangle的类，我希望他能旋转，怎么办呢，我在script函数中，让角度不断+1，就实现了。具体看代码

