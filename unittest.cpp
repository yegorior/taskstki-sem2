#include "CppUnitTest.h"

#include "Point.h"
#include "polygon.h"
#include "square.h"

#include <cmath>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace geometry;

namespace UnitTests {

TEST_CLASS(PointTests) {
public:
    TEST_METHOD(ConstructorTest) {
        Point point(3.0, 4.0);

        Assert::AreEqual(3.0, point.getX(), 0.000001);
        Assert::AreEqual(4.0, point.getY(), 0.000001);
    }

    TEST_METHOD(DefaultConstructorTest) {
        Point point;

        Assert::AreEqual(0.0, point.getX(), 0.000001);
        Assert::AreEqual(0.0, point.getY(), 0.000001);
    }

    TEST_METHOD(EqualityOperatorTest) {
        Point first(1.0, 2.0);
        Point second(1.0, 2.0);
        Point third(2.0, 1.0);

        Assert::IsTrue(first == second);
        Assert::IsFalse(first == third);
    }

    TEST_METHOD(InequalityOperatorTest) {
        Point first(1.0, 2.0);
        Point second(1.0, 2.0);
        Point third(2.0, 1.0);

        Assert::IsFalse(first != second);
        Assert::IsTrue(first != third);
    }

    TEST_METHOD(OutputOperatorTest) {
        Point point(3.0, 4.0);
        std::stringstream stream;

        stream << point;

        Assert::AreEqual(std::string("(3, 4)"), stream.str());
    }

    TEST_METHOD(InputOperatorWithBracketsTest) {
        Point point;
        std::stringstream stream("(3, 4)");

        stream >> point;

        Assert::AreEqual(3.0, point.getX(), 0.000001);
        Assert::AreEqual(4.0, point.getY(), 0.000001);
    }

    TEST_METHOD(InputOperatorWithoutBracketsTest) {
        Point point;
        std::stringstream stream("3 4");

        stream >> point;

        Assert::AreEqual(3.0, point.getX(), 0.000001);
        Assert::AreEqual(4.0, point.getY(), 0.000001);
    }
};

TEST_CLASS(SquareTests) {
public:
    TEST_METHOD(ConstructorByPointsTest) {
        Point first(0.0, 0.0);
        Point second(0.0, 2.0);
        Point third(2.0, 2.0);
        Point fourth(2.0, 0.0);

        Square square(first, second, third, fourth);

        Assert::AreEqual(4.0, square.getArea(), 0.000001);
        Assert::AreEqual(8.0, square.getPerimeter(), 0.000001);
        Assert::AreEqual(std::sqrt(2.0), square.getCircumradius(), 0.000001);
    }

    TEST_METHOD(ConstructorByCoordinatesTest) {
        Square square(0.0, 0.0, 0.0, 3.0, 3.0, 3.0, 3.0, 0.0);

        Assert::AreEqual(9.0, square.getArea(), 0.000001);
        Assert::AreEqual(12.0, square.getPerimeter(), 0.000001);
        Assert::AreEqual(3.0 * std::sqrt(2.0) / 2.0, square.getCircumradius(), 0.000001);
    }

    TEST_METHOD(ToStringMethodTest) {
        Square square(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        std::string result = square.ToString();

        Assert::IsTrue(result.find("Square") != std::string::npos);
        Assert::IsTrue(result.find("v1=") != std::string::npos);
        Assert::IsTrue(result.find("(0, 0)") != std::string::npos);
    }

    TEST_METHOD(GetAreaTest) {
        Square square(1.0, 1.0, 1.0, 5.0, 5.0, 5.0, 5.0, 1.0);

        Assert::AreEqual(16.0, square.getArea(), 0.000001);
    }

    TEST_METHOD(GetPerimeterTest) {
        Square square(1.0, 1.0, 1.0, 5.0, 5.0, 5.0, 5.0, 1.0);

        Assert::AreEqual(16.0, square.getPerimeter(), 0.000001);
    }

    TEST_METHOD(GetCircumradiusTest) {
        Square square(1.0, 1.0, 1.0, 5.0, 5.0, 5.0, 5.0, 1.0);

        Assert::AreEqual(4.0 * std::sqrt(2.0) / 2.0, square.getCircumradius(), 0.000001);
    }

    TEST_METHOD(ReadMethodTest) {
        Square square(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0);
        std::stringstream stream("(0, 0) (0, 2) (2, 2) (2, 0)");

        square.read(stream);

        Assert::AreEqual(4.0, square.getArea(), 0.000001);
        Assert::AreEqual(8.0, square.getPerimeter(), 0.000001);
    }

    TEST_METHOD(InputOperatorForPolygonTest) {
        Square square(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0);
        Polygon& polygon = square;
        std::stringstream stream("(0, 0) (0, 2) (2, 2) (2, 0)");

        stream >> polygon;

        Assert::AreEqual(4.0, polygon.getArea(), 0.000001);
        Assert::AreEqual(8.0, polygon.getPerimeter(), 0.000001);
    }

    TEST_METHOD(OutputOperatorForPolygonTest) {
        Square square(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        Polygon& polygon = square;
        std::stringstream stream;

        stream << polygon;

        Assert::IsTrue(stream.str().find("Square") != std::string::npos);
    }

    TEST_METHOD(EqualityOperatorTest) {
        Square first(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        Square second(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        Square third(0.0, 0.0, 0.0, 3.0, 3.0, 3.0, 3.0, 0.0);

        Assert::IsTrue(first == second);
        Assert::IsFalse(first == third);
    }

    TEST_METHOD(InequalityOperatorTest) {
        Square first(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        Square second(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        Square third(0.0, 0.0, 0.0, 3.0, 3.0, 3.0, 3.0, 0.0);

        Assert::IsFalse(first != second);
        Assert::IsTrue(first != third);
    }

    TEST_METHOD(StaticToStringTest) {
        Square square(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        std::string result = Square::ToString(square);

        Assert::IsTrue(result.find("Square") != std::string::npos);
    }

    TEST_METHOD(StaticReadFromStreamTest) {
        std::stringstream stream("(0, 0) (0, 2) (2, 2) (2, 0)");

        Square square = Square::readFromStream(stream);

        Assert::AreEqual(4.0, square.getArea(), 0.000001);
        Assert::AreEqual(8.0, square.getPerimeter(), 0.000001);
    }

    TEST_METHOD(InvalidSquareThrowsExceptionTest) {
        auto action = []() {
            Square square(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 3.0, 0.0);
        };

        Assert::ExpectException<std::invalid_argument>(action);
    }

    TEST_METHOD(PolygonStaticToStringTest) {
        Square square(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0);
        Polygon& polygon = square;
        std::string result = Polygon::ToString(polygon);

        Assert::IsTrue(result.find("Square") != std::string::npos);
    }

    TEST_METHOD(CollectionOfPolygonsTest) {
        std::vector<std::unique_ptr<Polygon>> polygons;
        polygons.push_back(std::make_unique<Square>(0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0));
        polygons.push_back(std::make_unique<Square>(0.0, 0.0, 0.0, 3.0, 3.0, 3.0, 3.0, 0.0));

        Assert::AreEqual(4.0, polygons[0]->getArea(), 0.000001);
        Assert::AreEqual(9.0, polygons[1]->getArea(), 0.000001);
    }
};

}
