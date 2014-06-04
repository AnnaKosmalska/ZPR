/*! \file Tile.hpp
   \brief Plik naglowkowy klasy Tile reprezentujacej jedna karte w grze.

   \author Anna Wujek
 */

#ifndef TILE
#define TILE

/*! \class Tile
  \brief reprezentuje jedna karte w grze
*/
class Tile
{
private:
  int ID;
  /*!<identyfikator karty*/
public:
  /*! \brief konstruktor
   */
  Tile();
  /*! \brief konstruktor z parametrem
    
    \param id karty
  */
  Tile(int ID);
  /*! \brief destruktor
   */
  ~Tile();
  /*! \brief pobranie id karty

    \return id karty
  */
  int getID() const;
  /* \brief przeciazony operator porwnania

     \return wynik ==
   */
  bool operator==(const Tile& tile) const;
};

#endif
