#pragma once
#include <span>
#include "Cell.hpp"
#include <memory>   
#include <vector>      
#include <algorithm>   
#include <string>      
#include <map>     

class SudokuRule {
    virtual ~SudokuRule() = default;
    virtual const char* name() const = 0;
    virtual bool check(std::span<Cell> field) const = 0; // проверка всего пол€
};

class RuleNonZeroCount : public SudokuRule {
    const char* name() const override { return "non_zero_count"; }
    bool check(std::span<Cell> field) const override {
        // проста€ проверка-демо: в поле есть хоть что-то заполненное
        for (Cell& c : field) if (c.getValue() != 0) return true;
        return false;
    }
};

class RuleNoFixedZero : public SudokuRule {
    const char* name() const override { return "no_fixed_zero"; }
    bool check(std::span<Cell> field) const override {
        // демо: фиксированна€ клетка не должна быть 0
        for (Cell& c : field) if (c.getIs_fixed() && c.getValue() == 0) return false;
        return true;
    }
};


template <class TRule>
    requires std::derived_from<TRule, SudokuRule>


class RuleEngine {
public:
    RuleEngine() = default;                      // Ќ≈шаблонный
    std::size_t size() const { return rules.size(); } // Ќ≈шаблонный

    void add(std::unique_ptr<TRule> r) {         // Ќ≈шаблонный
        rules.push_back(std::move(r));
    }

    bool all_ok(std::span<const Cell> field) const { // Ќ≈шаблонный
        return std::all_of(rules.begin(), rules.end(),
            [&](auto const& r) { return r->check(field); });
    }

    template <class Pred>                         // шаблонный метод
    TRule* find_if(Pred p) const {
        auto it = std::find_if(rules.begin(), rules.end(),
            [&](auto const& r) { return p(*r); });
        return (it == rules.end()) ? nullptr : it->get();
    }

private:
    std::vector<std::unique_ptr<TRule>> rules;
};
