#include <Game.h>
#include <iostream>
#include "Matrix3.h"

#include <vector>

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

vector<gpp::Vector3> cube;

Matrix3 matrix;

Game::~Game(){}

void changeThing();

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml


	cube.push_back(gpp::Vector3(1.0f, -1.0f, -5.0f)); //3 - 0
	cube.push_back(gpp::Vector3(-1.0f, -1.0f, -5.0f)); //2 - 1
	cube.push_back(gpp::Vector3(-1.0f, 1.0f, -5.0f)); //1 - 2
	cube.push_back(gpp::Vector3(1.0f, 1.0f, -5.0f)); //4 - 3
	cube.push_back(gpp::Vector3(1.0f, -1.0f, -10.0f)); //7 - 4
	cube.push_back(gpp::Vector3(1.0f, 1.0f, -10.0f)); //8 - 5
	cube.push_back(gpp::Vector3(-1.0f, -1.0f, -10.0f)); //6 - 6




	
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//face one
		//123
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(1).x, cube.at(1).y, cube.at(1).z); //1
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z); //2

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z); //2
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4

		////face two
		////437
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //7

		//487
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z); //8
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //7


		////face three
		////876
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z); //8
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //7
		glVertex3f(cube.at(6).x, cube.at(6).y, cube.at(6).z); //6


		////856
		//glColor3f(1.0f, 1.0f, 0.0f);
		//glVertex3f(1.0f, 1.0f, -10.0f); // 8
		//glVertex3f(-1.0f, 1.0f, -10.0f); // 5
		//glVertex3f(-1.0f, -1.0f, -10.0f); // 6

		////face four
		////562
		//glColor3f(1.0f, 0.0f, 1.0f);
		//glVertex3f(-1.0f, 1.0f, -10.0f); // 5
		//glVertex3f(-1.0f, -1.0f, -10.0f); // 6
		//glVertex3f(-1.0f, 1.0f, -5.0f); // 2

		////612
		//glColor3f(1.0f, 1.0f, 1.0f);
		//glVertex3f(-1.0f, -1.0f, -10.0f); // 6
		//glVertex3f(-1.0f, -1.0f, -5.0f); // 1
		//glVertex3f(-1.0f, 1.0f, -5.0f); // 2

		////bottom
		////623
		//glColor3f(1.0f, 0.0f, 1.0f);
		//glVertex3f(-1.0f, -1.0f, -10.0f); // 6
		//glVertex3f(-1.0f, 1.0f, -5.0f); // 2
		//glVertex3f(1.0f, -1.0f, -5.0f); // 3 

		////673
		//glColor3f(0.0f, 0.0f, 1.0f);
		//glVertex3f(-1.0f, -1.0f, -10.0f); // 6
		//glVertex3f(1.0f, -1.0f, -10.0f); // 7
		//glVertex3f(1.0f, -1.0f, -5.0f); // 3 

		////top
		////514
		//glColor3f(1.0f, 1.0f, 0.0f);
		//glVertex3f(-1.0f, 1.0f, -10.0f); // 5
		//glVertex3f(-1.0f, -1.0f, -5.0f); // 1
		//glVertex3f(1.0f, 1.0f, -5.0f); // 4

		////584
		//glVertex3f(-1.0f, 1.0f, -10.0f); // 5
		//glVertex3f(1.0f, 1.0f, -10.0f); // 8
		//glVertex3f(1.0f, 1.0f, -5.0f); // 4

	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		std::cout << "Rotate y attempt left" << std::endl;
		cube[0] = Matrix3::RotationY(.1) * cube[0];
		cube[1] = Matrix3::RotationY(.1) * cube[1];
		cube[2] = Matrix3::RotationY(.1) * cube[2];
		cube[3] = Matrix3::RotationY(.1) * cube[3];
		cube[4] = Matrix3::RotationY(.1) * cube[4];
		cube[5] = Matrix3::RotationY(.1) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		std::cout << "Rotate y attempt right" << std::endl;
		cube[0] = Matrix3::RotationY(-.1) * cube[0];
		cube[1] = Matrix3::RotationY(-.1) * cube[1];
		cube[2] = Matrix3::RotationY(-.1) * cube[2];
		cube[3] = Matrix3::RotationY(-.1) * cube[3];
		cube[4] = Matrix3::RotationY(-.1) * cube[4];
		cube[5] = Matrix3::RotationY(-.1) * cube[5];
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		std::cout << "Rotate x attempt up" << std::endl;
		cube[0] = Matrix3::RotationX(.1) * cube[0];
		cube[1] = Matrix3::RotationX(.1) * cube[1];
		cube[2] = Matrix3::RotationX(.1) * cube[2];
		cube[3] = Matrix3::RotationX(.1) * cube[3];
		cube[4] = Matrix3::RotationX(.1) * cube[4];
		cube[5] = Matrix3::RotationX(.1) * cube[5];
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		std::cout << "Rotate x attempt down" << std::endl;
		cube[0] = Matrix3::RotationX(-.1) * cube[0];
		cube[1] = Matrix3::RotationX(-.1) * cube[1];
		cube[2] = Matrix3::RotationX(-.1) * cube[2];
		cube[3] = Matrix3::RotationX(-.1) * cube[3];
		cube[4] = Matrix3::RotationX(-.1) * cube[4];
		cube[5] = Matrix3::RotationX(-.1) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "Translate attempt forward" << std::endl;
		cube[0] = Matrix3::Translate(-.01,0) * cube[0];
		cube[1] = Matrix3::Translate(-.01, 0) * cube[1];
		cube[2] = Matrix3::Translate(-.01, 0) * cube[2];
		cube[3] = Matrix3::Translate(-.01, 0) * cube[3];
		cube[4] = Matrix3::Translate(-.01, 0) * cube[4];
		cube[5] = Matrix3::Translate(-.01, 0) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::cout << "Translate attempt back" << std::endl;
		cube[0] = Matrix3::Translate(.01, 0) * cube[0];
		cube[1] = Matrix3::Translate(.01, 0) * cube[1];
		cube[2] = Matrix3::Translate(.01, 0) * cube[2];
		cube[3] = Matrix3::Translate(.01, 0) * cube[3];
		cube[4] = Matrix3::Translate(.01, 0) * cube[4];
		cube[5] = Matrix3::Translate(.01, 0) * cube[5];

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		std::cout << "Scale attempt smol" << std::endl;
		cube[0] = Matrix3::Scale(99, 99) * cube[0];
		cube[1] = Matrix3::Scale(99, 99) * cube[1];
		cube[2] = Matrix3::Scale(99, 99) * cube[2];
		cube[3] = Matrix3::Scale(99, 99) * cube[3];
		cube[4] = Matrix3::Scale(99, 99) * cube[4];
		cube[5] = Matrix3::Scale(99, 99) * cube[5];

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "Scale attempt big" << std::endl;
		cube[0] = Matrix3::Scale(101, 101) * cube[0];
		cube[1] = Matrix3::Scale(101, 101) * cube[1];
		cube[2] = Matrix3::Scale(101, 101) * cube[2];
		cube[3] = Matrix3::Scale(101, 101) * cube[3];
		cube[4] = Matrix3::Scale(101, 101) * cube[4];
		cube[5] = Matrix3::Scale(101, 101) * cube[5];

	}

	changeThing();
	
	//cout << "Update up" << endl;
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	//glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

void changeThing()
{
	glNewList(1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//face one
		//123
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(1).x, cube.at(1).y, cube.at(1).z); //1
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z); //2

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(2).x, cube.at(2).y, cube.at(2).z); //2
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4

		////face two
		////437
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4
		glVertex3f(cube.at(0).x, cube.at(0).y, cube.at(0).z); //3
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //7

		//487
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(cube.at(3).x, cube.at(3).y, cube.at(3).z); //4
		glVertex3f(cube.at(5).x, cube.at(5).y, cube.at(5).z); //3
		glVertex3f(cube.at(4).x, cube.at(4).y, cube.at(4).z); //7

		
	}
	glEnd();
	glEndList();
}
