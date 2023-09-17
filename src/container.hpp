#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstdint>
#include <iostream>
#include <memory>

#include "chess.hpp"

namespace ChessGame
{
    template <class T>
    class Container
    {
    protected:
        bool isOccupied = false;
    public:
        std::shared_ptr<T> data = nullptr;
        explicit Container() {};
        explicit Container(std::shared_ptr<T> data) : data(std::move(data)) { };
        virtual uint32_t Contain(std::shared_ptr<T> data) = 0;
        virtual void Remove() = 0;
    };

    template <class _Chess> class ChessContainer;
    template <class _Chess> std::ostream &operator<<(std::ostream &os, const ChessContainer<_Chess> &container);
    template <class _Chess>
    class ChessContainer : public Container<_Chess>
    {
    private:
        const char *DEFAULT_SYMBOL = "+";
    public:
        uint8_t row;
        uint8_t col;
        explicit ChessContainer(uint8_t row, uint8_t col) : row(row), col(col) { };
        explicit ChessContainer(uint8_t row, uint8_t col, std::shared_ptr<_Chess> chess) : Container<_Chess>(chess), row(row), col(col) { };

        uint32_t Contain(std::shared_ptr<_Chess> chess) override;
        void Remove() override;

        /* the same as _Chess, declare _Chess_ to avoid gcc complain */
        // template<class _Chess_>
        friend std::ostream &operator<< <_Chess>(std::ostream &os, const ChessContainer<_Chess> &container);
    };

    template <class _Chess>
    std::ostream &operator<<(std::ostream &os, const ChessContainer<_Chess> &container)
    {
        if (container.isOccupied) {
            return os << *container.data;
        }

        return os << container.DEFAULT_SYMBOL;
    }
}

#endif