/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
/****************************************************************************
  History

$Log: not supported by cvs2svn $
Revision 1.3  2004/04/28 16:31:17  turini
Changed :
in SolidAngle(vind) :
double da0=DiedralAngle(EV(vind,0));
double da1=DiedralAngle(EV(vind,1));
double da2=DiedralAngle(EV(vind,2));
in
double da0=DiedralAngle(EofV(vind,0));
double da1=DiedralAngle(EofV(vind,1));
double da2=DiedralAngle(EofV(vind,2));

Changed :
in DiedralAngle(edgeind) :
int f1=FE(edgeind,0);
int f2=FE(edgeind,1);
in
int f1=FofE(edgeind,0);
int f2=FofE(edgeind,1);

Changed :
in DiedralAngle(edgeind) :
Point3d p0=FV(f1,0)->P();
Point3d p1=FV(f1,1)->P();
Point3d p2=FV(f1,2)->P();
in
Point3d p0=_v[FofV(f1,0)];
Point3d p1=_v[FofV(f1,1)];
Point3d p2=_v[FofV(f1,2)];

Changed :
in DiedralAngle(edgeind) :
p0=FV(f2,0)->P();
p1=FV(f2,1)->P();
p2=FV(f2,2)->P();
in
p0=_v[FofV(f2,0)];
p1=_v[FofV(f2,1)];
p2=_v[FofV(f2,2)];

Revision 1.2  2004/04/28 11:37:15  pietroni
*** empty log message ***

Revision 1.1  2004/04/22 13:19:12  ganovelli
first version

Revision 1.2  2004/04/20 16:26:48  pietroni
*** empty log message ***

Revision 1.1  2004/04/15 08:54:20  pietroni
*** empty log message ***

Revision 1.1  2004/04/08 01:13:31  pietroni
Initial commit


****************************************************************************/
#ifndef __VCG_TETRA3
#define __VCG_TETRA3

namespace vcg {
/** \addtogroup space */
/*@{*/
/** 
		Templated class for storing a generic tetrahedron


 */
class Tetra
{
public:

 
//Tatrahedron Functions to retrieve information about relation between faces of tetrahedron(faces,adges,vertices).

  static int VofE(const int &indexE,const int &indexV)
  {	assert ((indexE<6)&&(indexV<2));
   static int edgevert[6][2] ={{0,1},
					{0,2},
					{0,3},
					{1,2},
					{1,3},
					{2,3}};
   return (edgevert[indexE][indexV]);
  }

	static int VofF(const int &indexF,const int &indexV)
	{	assert ((indexF<4)&&(indexV<3));
    static int facevert[4][3]={{0,1,2},
					{0,3,1},
					{0,2,3},
					{1,3,2}};
		return (facevert[indexF][indexV]);
	}

  static int EofV(const int &indexV,const int &indexE) 
	{	
    assert ((indexE<3)&&(indexV<4));
		static int vertedge[4][3]={{0,1,2},
											{0,3,4},
											{5,1,3},
											{4,5,2}};
		return vertedge[indexV][indexE];
	}

 static int EofF(const int &indexF,const int &indexE) 
	{	assert ((indexF<4)&&(indexE<3));
    static int faceedge[4][3]={{0,3,1},
					{2,4,0},
					{1,5,2},
					{4,5,3}
					};
		return faceedge [indexF][indexE];
	}

	static int FofV(const int &indexV,const int &indexF)
	{	
    assert ((indexV<4)&&(indexF<3));
    static int vertface[4][3]={{0,1,2},
					{0,3,1},
					{0,2,3},
					{1,3,2}};
		return vertface[indexV][indexF];
	}
  
  static int FofE(const int &indexE,const int &indexSide) 
	{	assert ((indexE<6)&&(indexSide<2));
    static int edgeface[6][2]={{0,1},
					{0,2},
					{1,2},
					{0,3},
					{1,3},
					{2,3}};
		return edgeface [indexE][indexSide];
	}

static int VofEE(const int &indexE0,const int &indexE1)
{
  assert ((indexE0<6)&&(indexE0>=0));
  assert ((indexE1<6)&&(indexE1>=0));
  static int edgesvert[6][6]={{-1,0,0,1,1,-1},
  {0,-1,0,2,-1,2},
  {0,0,-1,-1,3,3},
  {1,2,-1,-1,1,2},
  {1,-1,3,1,-1,3},
  {-1,2,3,2,3,-1}};
return (edgesvert[indexE0][indexE1]);
}

static int VofFFF(const int &indexF0,const int &indexF1,const int &indexF2)
{
  assert ((indexF0<4)&&(indexF0>=0));
  assert ((indexF1<4)&&(indexF1>=0));
  assert ((indexF2<4)&&(indexF2>=0));
  static int facesvert[4][4][4]={
		{//0
			{-1,-1,-1,-1},{-1,-1,0,1},{-1,0,-1,2},{-1,1,2,-1}
		},
		{//1
			{-1,-1,0,1},{-1,-1,-1,-1},{0,-1,-1,3},{1,-1,3,-1}
		},
		{//2
			{-1,0,-1,2},{0,-1,-1,3},{-1,-1,-1,-1},{2,3,-1,-1}
		},
		{//3
			{-1,1,2,-1},{1,-1,3,-1},{2,3,-1,-1},{-1,-1,-1,-1}
		}
	};
  return facesvert[indexF0][indexF1][indexF2];
}

static int EofFF(const int &indexF0,const int &indexF1)
{
  assert ((indexF0<4)&&(indexF0>=0));
  assert ((indexF1<4)&&(indexF1>=0));
  static	int facesedge[4][4]={{-1,  0,  1,  3},
						  { 0, -1,  2,  4},
						  { 1,  2, -1,  5},
						  { 3,  4,  5, -1}};
  return (facesedge[indexF0][indexF1]);
}

static int EofVV(const int &indexV0,const int &indexV1) 
{
      assert ((indexV0<4)&&(indexV0>=0));
      assert ((indexV1<4)&&(indexV1>=0));
      static	int verticesedge[4][4]={{-1,  0,  1,  2},
						  { 0, -1,  3,  4},
						  { 1,  3, -1,  5},
						  { 2,  4,  5, -1}};
			
			return verticesedge[indexV0][indexV1];
}

static FofVVV(const int &indexV0,const int &indexV1,const int &indexV2)
{

assert ((indexV0<4)&&(indexV0>=0));
assert ((indexV1<4)&&(indexV1>=0));
assert ((indexV2<4)&&(indexV2>=0));

static int verticesface[4][4][4]={
		{//0
			{-1,-1,-1,-1},{-1,-1,0,1},{-1,0,-1,2},{-1,1,2,-1}
		},
		{//1
			{-1,-1,0,1},{-1,-1,-1,-1},{0,-1,-1,3},{1,-1,3,-1}
		},
		{//2
			{-1,0,-1,2},{0,-1,-1,3},{-1,-1,-1,-1},{2,3,-1,-1}
		},
		{//3
			{-1,1,2,-1},{1,-1,3,-1},{2,3,-1,-1},{-1,-1,-1,-1}
		}
	};
return verticesface[indexV0][indexV1][indexV2];
}

static int FofEE(const int &indexE0,const int &indexE1)
{
  assert ((indexE0<6)&&(indexE0>=0));
  assert ((indexE1<6)&&(indexE1>=0));
  static	int edgesface[6][6]={{-1,0,1,0,1,-1},
    {0,-1,2,0,-1,2},
    {1,2,-1,-1,1,2},
    {0,0,-1,-1,3,3},
    {1,-1,1,3,-1,3},
    {-1,2,2,3,3,-1}};
						  
			return edgesface[indexE0][indexE1];
}
};

/** \addtogroup space */
/*@{*/
/** 
		Templated class for storing a generic tetrahedron in a 3D space.
    Note the relation with the Face class of TetraMesh complex, both classes provide the P(i) access functions to their points and therefore they share the algorithms on it (e.g. area, normal etc...)
 */
 template <class SCALAR_TETRA_TYPE> class Tetra3: public Tetra
{
public:
  typedef typename SCALAR_TETRA_TYPE ScalarType;
	typedef typename Point3< ScalarType > CoordType;

/*********************************************
  
**/

private:
	/// Vector of the 4 points that defines the tetrahedron
	CoordType _v[4];

public:

/// Shortcut per accedere ai punti delle facce
	inline CoordType & P0( const int j ) { return _v[j];}
	inline CoordType & P1( const int j ) { return _v[(j+1)%4];}
	inline CoordType & P2( const int j ) { return _v[(j+2)%4];}
  inline CoordType & P3( const int j ) { return _v[(j+3)%4];}

	inline const CoordType &  P0( const int j ) const { return _v[j];}
	inline const CoordType &  P1( const int j ) const { return _v[(j+1)%4];}
	inline const CoordType &  P2( const int j ) const { return _v[(j+2)%4];}
  inline const CoordType &  P3( const int j ) const { return _v[(j+3)%4];}

	inline const CoordType & cP0( const int j ) const { return _v[j];}
	inline const CoordType & cP1( const int j ) const { return _v[(j+1)%4];}
	inline const CoordType & cP2( const int j ) const { return _v[(j+2)%4];}
  inline const CoordType & cP3( const int j ) const { return _v[(j+3)%4];}

/// compute and return the volume of a tetrahedron
  	ScalarType ComputeVolume(){
				return (( _v[2]-_v[0])^(_v[1]-_v[0] ))*(_v[3]-_v[0])/6.0;
		}
/// compute and return the barycenter of a tetrahedron
 CoordType ComputeBarycenter()
	{	
			return((_v[0] + _v[1] + _v[2]+ _v[3])/4);
	}

/// compute and return the solid angle on a vertex
double SolidAngle(int vind)
	{	
		double da0=DiedralAngle(EV(vind,0));
		double da1=DiedralAngle(EV(vind,1));
		double da2=DiedralAngle(EV(vind,2));

			return((da0 + da1 + da2)- M_PI);
	}

/// compute and return the diadedral angle on an edge
	double DiedralAngle(int edgeind)
  {
		int f1=FE(edgeind,0);
		int f2=FE(edgeind,1);
		Point3d p0=FV(f1,0)->P();
		Point3d p1=FV(f1,1)->P();
		Point3d p2=FV(f1,2)->P();
		Point3d norm1=((p1-p0)^(p2-p0));
		p0=FV(f2,0)->P();
		p1=FV(f2,1)->P();
		p2=FV(f2,2)->P();
		Point3d norm2=((p1-p0)^(p2-p0));
		norm1.Normalize();
		norm2.Normalize();
	 return (M_PI-acos(double(norm1*norm2)));
	}

/// compute and return the aspect ratio of the tetrahedron 
ScalarType ComputeAspectRatio()
	{	
		double a0=SolidAngle(0);
		double a1=SolidAngle(1);
		double a2=SolidAngle(2);
		double a3=SolidAngle(3);
		return (min(a0,min(a1,min(a2,a3))));
	}


}; //end Class

// Returns the normal to the plane passing through p0,p1,p2
template<class TetraType>
Point3<typename TetraType::ScalarType> Normal(const TetraType &t,int face)
{
  return(((t.P0(Tetra::VofF(face,1))-t.P0(Tetra::VofF(face,0)))^(t.P0(Tetra::VofF(face,2))-t.P0(Tetra::VofF(face,0)))).Normalize());
}

}	 // end namespace


#endif

